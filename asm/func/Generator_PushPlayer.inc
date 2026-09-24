	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r6, _080B2998 @ =0x03002BE0
	ldr r3, [r6]
	movs r1, #0x2c
	ldrsh r2, [r3, r1]
	adds r7, r0, #0
	adds r7, #0x60
	movs r4, #0
	ldrsh r1, [r7, r4]
	subs r2, r2, r1
	movs r5, #0x30
	ldrsh r1, [r3, r5]
	adds r0, #0x64
	mov r8, r0
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r3, r1, r0
	adds r0, r2, #0
	cmp r2, #0
	bge _080B2926
	rsbs r0, r2, #0
_080B2926:
	cmp r0, #0x7f
	bgt _080B298C
	adds r0, r3, #0
	cmp r3, #0
	bge _080B2932
	rsbs r0, r3, #0
_080B2932:
	cmp r0, #0x7f
	bgt _080B298C
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r0, r0, r1
	ldr r1, _080B299C @ =0x00003FFF
	cmp r0, r1
	bgt _080B298C
	adds r0, r2, #0
	adds r1, r3, #0
	bl ArcTan2_8
	ldr r4, [r6]
	mov ip, r4
	ldr r4, _080B29A0 @ =0x085B0A08
	adds r1, r0, #0
	adds r1, #0x40
	movs r3, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r5, #0
	ldrsh r2, [r1, r5]
	lsls r1, r2, #6
	adds r1, r1, r2
	asrs r1, r1, #0xb
	ldrh r7, [r7]
	adds r1, r1, r7
	mov r2, ip
	strh r1, [r2, #0x2c]
	ldr r2, [r6]
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #6
	adds r0, r0, r1
	asrs r0, r0, #0xb
	mov r4, r8
	ldrh r4, [r4]
	adds r0, r0, r4
	strh r0, [r2, #0x30]
_080B298C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B2998: .4byte 0x03002BE0
_080B299C: .4byte 0x00003FFF
_080B29A0: .4byte 0x085B0A08
