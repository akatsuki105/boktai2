	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xa4
	lsls r1, r1, #1
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0800FC88
	ldr r1, _0800FC80 @ =Entity4D4D_Update
	ldr r2, _0800FC84 @ =Entity4D4D_Destroy
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl Entity4D4D_Init
	cmp r0, #0
	bge _0800FC88
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0800FC8A
	.align 2, 0
_0800FC80: .4byte Entity4D4D_Update
_0800FC84: .4byte Entity4D4D_Destroy
_0800FC88:
	adds r0, r4, #0
_0800FC8A:
	pop {r4, r5}
	pop {r1}
	bx r1
