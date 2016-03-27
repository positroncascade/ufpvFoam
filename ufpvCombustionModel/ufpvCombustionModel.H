#ifndef ufpvCombustionModel_H
#define ufpvCombustionModel_H

#include "combustionModel.H"
#include "autoPtr.H"
#include "runTimeSelectionTables.H"
#include "primitiveFieldsFwd.H"
#include "volFieldFwd.H"
#include "zeroGradientFvPatchFields.H"
#include "surfaceFieldsFwd.H"
#include "fvMatricesFwd.H"
#include "tableSolver.H"
#include "fvm.H"
#include "fvc.H"
#include "fvMatrices.H"
#include "autoPtr.H"

namespace Foam
{
namespace combustionModels

class ufpvCombustionModel
:
	public combustionModel
{

	ufpvCombustionModel(const ufpvCombustionModel&);

	void operator=(const ufpvCombustionModel&);

protected:
	
	volScalarField& p_;

	volScalarField& T_;

	volScalarField& rho_;

	volScalarField& Z_;

	volScalarField& varZ_;

	volScalarField& mu_;

	volScalarField& alpla_Z;

	volScalarField& alpla_C;

	volScalarField& omega_C;

        tableSolver solver_;
public:

	TypeName("ufpvCombustionModel");
 
        declareRunTimeSelectionTable
	(
		autoPtr,
		ufpvCombustionModel,
		dictionary,
		(
			const word& modelType,
			const fvMesh& mesh,
		),
		(modelType, mesh)
	);

	ufpvCombustionModel(const word& modelType, const fvMesh& mesh);

	static autoPtr<ufpvCombustionModel> New(const fvMesh& mesh);

	virtual ~upfvCombustionModel();

	inline const dictionary& coeff() const;

	virtual tmp<volScalarField> rho() const = 0;

	virtual bool read();


};

}
}

#endif
