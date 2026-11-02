	push {r4, lr}
	movs r1, #0x9a
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08053034
	ldr r1, _0805302C @ =Entity08052ffc_Update
	ldr r2, _08053030 @ =Entity08052ffc_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08052ffc_Init
	cmp r0, #0
	bge _08053034
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08053036
	.align 2, 0
_0805302C: .4byte Entity08052ffc_Update
_08053030: .4byte Entity08052ffc_Destroy
_08053034:
	adds r0, r4, #0
_08053036:
	pop {r4}
	pop {r1}
	bx r1
