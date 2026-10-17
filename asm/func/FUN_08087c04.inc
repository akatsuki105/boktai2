	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08087C58 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08087C1A
	adds r0, r4, #0
	movs r1, #0
	bl Coffin_SetState
_08087C1A:
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	ldr r0, _08087C5C @ =0x0000FFFB
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r2, _08087C60 @ =0x0000032A
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	bl FUN_08086024
	ldr r0, _08087C64 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08087CB6
	movs r5, #0xe5
	lsls r5, r5, #2
	adds r3, r4, r5
	ldrh r0, [r3]
	cmp r0, #0
	beq _08087C68
	adds r0, r4, #0
	bl FUN_08087a5c
	b _08087CB6
	.align 2, 0
_08087C58: .4byte 0x000001F5
_08087C5C: .4byte 0x0000FFFB
_08087C60: .4byte 0x0000032A
_08087C64: .4byte 0x030047A4
_08087C68:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	beq _08087C7C
	adds r0, r4, #0
	bl FUN_080856f4
	b _08087CB6
_08087C7C:
	ldr r5, _08087CA4 @ =0x0000040A
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08087CB0
	ldr r1, _08087CA8 @ =0x00000392
	adds r0, r4, r1
	ldrh r1, [r0]
	subs r5, #0x7a
	adds r0, r4, r5
	strh r1, [r0]
	ldr r1, _08087CAC @ =0x000003A6
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r5, #0x14
	adds r0, r4, r5
	strh r1, [r0]
	strh r2, [r3]
	b _08087CB6
	.align 2, 0
_08087CA4: .4byte 0x0000040A
_08087CA8: .4byte 0x00000392
_08087CAC: .4byte 0x000003A6
_08087CB0:
	adds r0, r4, #0
	bl FUN_08087bac
_08087CB6:
	pop {r4, r5}
	pop {r0}
	bx r0
