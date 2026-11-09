	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r1, #1
	movs r2, #0xb3
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08136B0A
	movs r0, #1
	b _08136B0C
_08136B0A:
	movs r0, #0
_08136B0C:
	cmp r0, #0
	beq _08136B30
	movs r0, #0xb3
	lsls r0, r0, #4
	adds r2, r4, r0
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08136B38 @ =0x00000AEC
	adds r4, r4, r1
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl Mover_Unlink
_08136B30:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08136B38: .4byte 0x00000AEC
