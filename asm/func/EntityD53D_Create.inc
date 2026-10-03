	push {r4, lr}
	bl FUN_0804ea10
	adds r4, r0, #0
	cmp r4, #0
	bne _0804EDC2
	movs r0, #0xc
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804EDC0
	ldr r1, _0804EDB8 @ =EntityD53D_Update
	ldr r2, _0804EDBC @ =EntityD53D_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityD53D_Init
	cmp r0, #0
	bge _0804EDC0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804EDC2
	.align 2, 0
_0804EDB8: .4byte EntityD53D_Update
_0804EDBC: .4byte EntityD53D_Destroy
_0804EDC0:
	adds r0, r4, #0
_0804EDC2:
	pop {r4}
	pop {r1}
	bx r1
