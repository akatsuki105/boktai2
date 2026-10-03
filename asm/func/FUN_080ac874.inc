	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	mov r3, ip
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldr r6, _080AC918 @ =0x0203B400
	ldr r5, _080AC91C @ =0x030046B8
	mov r8, r5
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _080AC920 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldrh r3, [r3, #0x1c]
	subs r3, #0xff
	asrs r0, r0, #3
	ldr r7, _080AC924 @ =0x000001FF
	adds r5, r7, #0
	ands r0, r5
	adds r3, r3, r0
	mov r0, ip
	strh r3, [r0, #0x1c]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r7, ip
	ldrh r3, [r7, #0x20]
	subs r3, #0xff
	asrs r0, r0, #3
	ands r0, r5
	adds r3, r3, r0
	strh r3, [r7, #0x20]
	mov r3, ip
	adds r3, #0x58
	strh r2, [r3]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	movs r0, #0x1f
	ands r2, r0
	ldrh r3, [r3]
	adds r2, r2, r3
	adds r5, r2, #0
	subs r5, #0xf
	adds r1, #1
	ands r1, r4
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	mov r3, ip
	adds r3, #0x5a
	movs r1, #3
	ands r0, r1
	ldrh r3, [r3]
	adds r0, r0, r3
	subs r4, r0, #1
	ldr r1, _080AC928 @ =0x085B0A08
	adds r2, #0x31
	movs r0, #0xff
	ands r2, r0
	lsls r2, r2, #1
	adds r2, r2, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	muls r0, r4, r0
	mov r2, r8
	cmp r0, #0
	blt _080AC92C
	asrs r3, r0, #0xc
	b _080AC932
	.align 2, 0
_080AC918: .4byte 0x0203B400
_080AC91C: .4byte 0x030046B8
_080AC920: .4byte 0x000003FF
_080AC924: .4byte 0x000001FF
_080AC928: .4byte 0x085B0A08
_080AC92C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AC932:
	mov r0, ip
	adds r0, #0x48
	strh r3, [r0]
	movs r0, #0xff
	ands r5, r0
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AC94E
	asrs r1, r0, #0xc
	b _080AC954
_080AC94E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AC954:
	mov r0, ip
	adds r0, #0x4c
	strh r1, [r0]
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AC998 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r7, _080AC99C @ =0x0203B400
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	mov r1, ip
	adds r1, #0x56
	strh r0, [r1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r3, ip
	str r0, [r3]
	mov r1, ip
	adds r1, #0x50
	movs r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC998: .4byte 0x000003FF
_080AC99C: .4byte 0x0203B400
