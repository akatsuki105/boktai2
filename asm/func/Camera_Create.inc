	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0823CCF0 @ =gCamera
	ldr r0, [r0]
	cmp r0, #0
	bne _0823CCFE
	movs r0, #7
	movs r1, #0xa4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0823CCFC
	ldr r1, _0823CCF4 @ =Camera_Update
	ldr r2, _0823CCF8 @ =Camera_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Camera_Init
	cmp r0, #0
	bge _0823CCFC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0823CCFE
	.align 2, 0
_0823CCF0: .4byte gCamera
_0823CCF4: .4byte Camera_Update
_0823CCF8: .4byte Camera_Destroy
_0823CCFC:
	adds r0, r4, #0
_0823CCFE:
	pop {r4, r5}
	pop {r1}
	bx r1
