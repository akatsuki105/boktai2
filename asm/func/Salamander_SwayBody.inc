	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r7, [r0]
	mov r0, ip
	ldr r3, [r0, #0x44]
	ldr r2, _081AB270 @ =gSineTable
	ldr r1, _081AB274 @ =0x00000CA2
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #1
	cmp r0, #0
	blt _081AB278
	asrs r1, r0, #0xc
	b _081AB27E
	.align 2, 0
_081AB270: .4byte gSineTable
_081AB274: .4byte 0x00000CA2
_081AB278:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081AB27E:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	mov r6, ip
	ldr r1, [r6, #0x44]
	ldr r3, _081AB2A0 @ =0x00000CA2
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #4
	cmp r0, #0
	blt _081AB2A4
	asrs r2, r0, #0xc
	b _081AB2AA
	.align 2, 0
_081AB2A0: .4byte 0x00000CA2
_081AB2A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081AB2AA:
	ldrh r0, [r1, #0x20]
	adds r0, r0, r2
	strh r0, [r1, #0x20]
	ldr r6, _081AB2F4 @ =0x00000CA2
	adds r1, r7, r6
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	movs r5, #1
	mov r8, r5
	ldr r0, _081AB2F8 @ =0x00000CAA
	adds r1, r7, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r0, #1
	cmp r8, r0
	bge _081AB332
	ldr r3, _081AB2FC @ =gSineTable
	mov sl, r3
	mov sb, r1
	adds r3, r7, #0
	adds r3, #0xd0
	ldr r4, _081AB300 @ =0x000007D9
	adds r2, r7, r4
	movs r4, #0xd0
	lsls r4, r4, #1
_081AB2DE:
	ldrb r0, [r2]
	lsls r0, r0, #1
	add r0, sl
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #2
	cmp r0, #0
	blt _081AB304
	asrs r0, r0, #0xc
	b _081AB30A
	.align 2, 0
_081AB2F4: .4byte 0x00000CA2
_081AB2F8: .4byte 0x00000CAA
_081AB2FC: .4byte gSineTable
_081AB300: .4byte 0x000007D9
_081AB304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081AB30A:
	ldr r6, _081AB3C0 @ =0x00000674
	adds r1, r3, r6
	muls r0, r5, r0
	ldrh r6, [r1]
	adds r0, r0, r6
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, #8
	strb r0, [r2]
	rsbs r5, r5, #0
	adds r3, r3, r4
	adds r2, r2, r4
	movs r0, #2
	add r8, r0
	mov r1, sb
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, #1
	cmp r8, r0
	blt _081AB2DE
_081AB332:
	mov r1, ip
	ldr r0, [r1, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r2, #0
	mov r8, r2
	ldr r3, _081AB3C4 @ =0x00000CAA
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r0, #1
	cmp r8, r0
	blt _081AB352
	b _081AB48A
_081AB352:
	add r6, sp, #4
	mov sl, r6
	add r6, sp, #0xc
	add r5, sp, #0x14
	movs r0, #0x80
	lsls r0, r0, #1
	mov sb, r0
_081AB360:
	movs r0, #0xd0
	mov r2, r8
	muls r2, r0, r2
	adds r2, r2, r7
	ldr r1, _081AB3C8 @ =0x00000744
	adds r2, r2, r1
	ldrh r0, [r2]
	ldrh r1, [r6]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r2, #0
	str r2, [sp]
	mov r0, sp
	add r1, sp, #0x1c
	ldr r2, _081AB3CC @ =0x05000002
	bl CpuSet
	mov r3, sb
	movs r4, #0xc0
	lsls r4, r4, #2
	subs r1, r3, r4
	adds r1, #1
	add r2, sp, #0x1c
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r4, r1, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	mov r3, sb
	subs r1, r0, r3
	movs r3, #0
	ldrsh r0, [r5, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	mov ip, r2
	cmp r0, #0
	blt _081AB3D0
	asrs r1, r0, #0xa
	b _081AB3D6
	.align 2, 0
_081AB3C0: .4byte 0x00000674
_081AB3C4: .4byte 0x00000CAA
_081AB3C8: .4byte 0x00000744
_081AB3CC: .4byte 0x05000002
_081AB3D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081AB3D6:
	ldrh r0, [r6]
	adds r0, r0, r1
	mov r4, sl
	strh r0, [r4]
	mov r0, sb
	movs r1, #0xc0
	lsls r1, r1, #2
	subs r3, r0, r1
	adds r1, r3, #1
	mov r2, ip
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	mov r0, sb
	rsbs r2, r0, #0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r1, r2, r1
	str r1, [sp, #0x24]
	movs r1, #2
	ldrsh r0, [r5, r1]
	ldr r1, [sp, #0x24]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r4, #0
	orrs r0, r4
	cmp r0, #0
	blt _081AB414
	asrs r1, r0, #0xa
	b _081AB41A
_081AB414:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081AB41A:
	ldrh r0, [r6, #2]
	adds r0, r0, r1
	mov r1, sl
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, ip
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r2, #4
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r3, #0
	orrs r0, r3
	cmp r0, #0
	blt _081AB448
	asrs r1, r0, #0xa
	b _081AB44E
_081AB448:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081AB44E:
	ldrh r0, [r6, #4]
	adds r0, r0, r1
	mov r4, sl
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	mov r2, sl
	bl Salamander_SetSegmentPos
	mov r1, r8
	adds r1, #1
	movs r0, #0xd0
	muls r0, r1, r0
	adds r0, r7, r0
	ldr r1, _081AB49C @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r2, #2
	add r8, r2
	ldr r3, _081AB4A0 @ =0x00000CAA
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r0, #1
	cmp r8, r0
	bge _081AB48A
	b _081AB360
_081AB48A:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AB49C: .4byte 0x00000674
_081AB4A0: .4byte 0x00000CAA
