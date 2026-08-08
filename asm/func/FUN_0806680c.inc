	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r1, _08066828 @ =0x030046A0
	ldr r0, [r1]
	ldr r4, _0806682C @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _08066830
	movs r0, #1
	b _08066832
	.align 2, 0
_08066828: .4byte 0x030046A0
_0806682C: .4byte 0x00000934
_08066830:
	movs r0, #0
_08066832:
	cmp r0, #0
	beq _0806686E
	movs r2, #0x99
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0x12
	beq _0806686E
	movs r0, #2
	ldr r1, [r1]
	ldr r4, _08066858 @ =0x00000934
	adds r1, r1, r4
	ldrh r1, [r1]
	ands r1, r0
	cmp r1, #0
	beq _0806685C
	movs r0, #1
	b _0806685E
	.align 2, 0
_08066858: .4byte 0x00000934
_0806685C:
	movs r0, #0
_0806685E:
	cmp r0, #0
	bne _08066872
	adds r0, r3, #0
	adds r0, #0x2c
	bl FUN_0809df78
	cmp r0, #0
	bne _08066872
_0806686E:
	movs r0, #0
	b _08066874
_08066872:
	movs r0, #1
_08066874:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
