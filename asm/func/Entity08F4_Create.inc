	push {r4, lr}
	movs r1, #0xcc
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DB9EC
	ldr r1, _081DB9E4 @ =Entity08F4_Update
	ldr r2, _081DB9E8 @ =Entity08F4_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08F4_Init
	cmp r0, #0
	bge _081DB9EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DB9EE
	.align 2, 0
_081DB9E4: .4byte Entity08F4_Update
_081DB9E8: .4byte Entity08F4_Destroy
_081DB9EC:
	adds r0, r4, #0
_081DB9EE:
	pop {r4}
	pop {r1}
	bx r1
