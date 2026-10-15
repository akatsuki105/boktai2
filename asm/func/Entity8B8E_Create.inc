	push {r4, lr}
	ldr r1, _081E85A8 @ =0x00001630
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E85B4
	ldr r1, _081E85AC @ =Entity8B8E_Update
	ldr r2, _081E85B0 @ =Entity8B8E_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity8B8E_Init
	cmp r0, #0
	bge _081E85B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E85B6
	.align 2, 0
_081E85A8: .4byte 0x00001630
_081E85AC: .4byte Entity8B8E_Update
_081E85B0: .4byte Entity8B8E_Destroy
_081E85B4:
	adds r0, r4, #0
_081E85B6:
	pop {r4}
	pop {r1}
	bx r1
