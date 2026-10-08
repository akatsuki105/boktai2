	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl EntityA628_UpdateBGVisibility
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0DDC
	adds r0, r4, #0
	bl EntityA628_UpdatePos
	add r5, sp, #4
	adds r6, r4, #0
	adds r6, #0x28
	ldrh r0, [r4, #0x28]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A0D40
	asrs r0, r0, #8
	b _080A0D46
_080A0D40:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A0D46:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A0D58
	asrs r0, r0, #8
	b _080A0D5E
_080A0D58:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A0D5E:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080A0D72
	asrs r1, r0, #8
	b _080A0D78
_080A0D72:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_080A0D78:
	subs r0, r2, r1
	strh r0, [r5, #2]
	adds r0, r2, r1
	strh r0, [r5, #4]
	ldr r2, _080A0DAC @ =0x030047C8
	movs r3, #0
	ldrsh r1, [r2, r3]
	add r0, sp, #4
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r4, r1, r0
	adds r3, r4, #0
	adds r3, #0x80
	movs r1, #2
	ldrsh r0, [r2, r1]
	add r1, sp, #4
	movs r2, #2
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	adds r5, r0, #0
	adds r5, #0x80
	cmp r4, #0
	blt _080A0DB0
	asrs r1, r4, #3
	b _080A0DB6
	.align 2, 0
_080A0DAC: .4byte 0x030047C8
_080A0DB0:
	rsbs r0, r4, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080A0DB6:
	adds r0, r5, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080A0DC2
	asrs r2, r0, #3
	b _080A0DC8
_080A0DC2:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r2, r0, #0
_080A0DC8:
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	subs r3, #0x78
	adds r0, r5, #0
	subs r0, #0x5a
	str r0, [sp]
	movs r0, #1
	bl Video_GenerateBGMap
_080A0DDC:
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
