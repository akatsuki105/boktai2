	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xcf
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E197C
	ldr r1, _081E1974 @ =Entity150F_Update
	ldr r2, _081E1978 @ =Entity150F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity150F_Init
	cmp r0, #0
	bge _081E197C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E197E
	.align 2, 0
_081E1974: .4byte Entity150F_Update
_081E1978: .4byte Entity150F_Destroy
_081E197C:
	adds r0, r4, #0
_081E197E:
	pop {r4, r5}
	pop {r1}
	bx r1
