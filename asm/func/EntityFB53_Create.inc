	push {r4, lr}
	movs r0, #2
	movs r1, #0x4c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804B9EC
	ldr r1, _0804B9E4 @ =EntityFB53_Update
	ldr r2, _0804B9E8 @ =EntityFB53_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityFB53_Init
	cmp r0, #0
	bge _0804B9EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804B9EE
	.align 2, 0
_0804B9E4: .4byte EntityFB53_Update
_0804B9E8: .4byte EntityFB53_Destroy
_0804B9EC:
	adds r0, r4, #0
_0804B9EE:
	pop {r4}
	pop {r1}
	bx r1
