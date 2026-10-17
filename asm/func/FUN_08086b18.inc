	push {r4, r5, r6, lr}
	ldr r5, _08086B8C @ =0x03002C00
	ldr r3, [r5]
	cmp r3, #0
	beq _08086BC2
	movs r4, #0xef
	lsls r4, r4, #2
	adds r2, r3, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r3, #0
	movs r1, #0xe
	bl Coffin_SetState
	ldr r3, [r5]
	movs r0, #0x81
	lsls r0, r0, #3
	adds r1, r3, r0
	movs r0, #0xf
	strh r0, [r1]
	ldr r0, _08086B90 @ =0x03002BE0
	ldr r2, [r0]
	movs r6, #0x2c
	ldrsh r1, [r2, r6]
	adds r4, r3, r4
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r4, r1, r0
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r0, r3, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r1, r1, r0
	cmp r4, #0
	bne _08086B6C
	cmp r1, #0
	beq _08086B98
_08086B6C:
	adds r0, r4, #0
	bl ArcTan2_8
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	ldr r2, [r5]
	adds r0, #7
	movs r1, #7
	ands r0, r1
	ldr r1, _08086B94 @ =0x00000404
	adds r2, r2, r1
	strh r0, [r2]
	b _08086BB6
	.align 2, 0
_08086B8C: .4byte 0x03002C00
_08086B90: .4byte 0x03002BE0
_08086B94: .4byte 0x00000404
_08086B98:
	ldr r2, _08086BC8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08086BCC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08086BD0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	ldr r6, _08086BD4 @ =0x00000404
	adds r1, r3, r6
	strh r0, [r1]
_08086BB6:
	ldr r0, _08086BD8 @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _08086BDC @ =0x00000402
	adds r0, r0, r1
	movs r1, #0x1d
	strh r1, [r0]
_08086BC2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08086BC8: .4byte 0x030046B8
_08086BCC: .4byte 0x000003FF
_08086BD0: .4byte 0x0203B400
_08086BD4: .4byte 0x00000404
_08086BD8: .4byte 0x03002C00
_08086BDC: .4byte 0x00000402
