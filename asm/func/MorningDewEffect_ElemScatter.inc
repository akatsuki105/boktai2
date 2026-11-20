	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	adds r6, r1, #0
	ldrb r0, [r6, #4]
	mov sb, r0
	adds r4, r6, #0
	adds r4, #0x18
	movs r1, #0
	mov r8, r1
_0801A3E4:
	mov r0, sb
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	ldr r7, _0801A424 @ =gSineTable
	adds r0, r0, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r6, #3]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r7, [r4, #0x18]
	adds r0, r0, r7
	strh r0, [r4, #0x18]
	ldrh r0, [r6, #6]
	cmp r0, #0x18
	bhi _0801A43A
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r2, _0801A424 @ =gSineTable
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0801A428
	asrs r1, r0, #0xc
	b _0801A42E
	.align 2, 0
_0801A424: .4byte gSineTable
_0801A428:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0801A42E:
	mov r2, sl
	ldrh r0, [r2, #0x1e]
	adds r0, r0, r1
	ldrb r7, [r6, #5]
	adds r0, r0, r7
	b _0801A43E
_0801A43A:
	ldrh r0, [r4, #0x1a]
	subs r0, #0xa
_0801A43E:
	strh r0, [r4, #0x1a]
	mov r1, sb
	lsls r0, r1, #1
	ldr r2, _0801A524 @ =gSineTable
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldrb r0, [r6, #3]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	movs r2, #0
	mov ip, r2
	strh r0, [r4, #0x1c]
	adds r0, r6, #0
	adds r0, #0x13
	mov r7, r8
	adds r5, r0, r7
	ldrb r1, [r5]
	adds r1, #1
	strb r1, [r5]
	movs r2, #0xff
	mov r0, sp
	strb r2, [r0]
	lsls r1, r1, #0x18
	ldr r2, _0801A528 @ =0x085AA970
	adds r0, r6, #0
	adds r0, #0x10
	adds r3, r0, r7
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	lsrs r1, r1, #0x18
	ldrh r0, [r0]
	cmp r1, r0
	blo _0801A4B6
	mov r7, ip
	strb r7, [r5]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	mov r1, sp
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #1
	bls _0801A4A0
	mov r2, ip
	strb r2, [r3]
_0801A4A0:
	mov r7, sl
	ldr r1, [r7, #0x28]
	ldrb r2, [r3]
	adds r2, #2
	adds r0, r4, #0
	bl Particle_SetPose
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r4, #0xe]
_0801A4B6:
	ldr r2, _0801A52C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801A530 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801A534 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0x4c
	mov r2, sb
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r7, #1
	add r8, r7
	adds r4, #0x28
	mov r0, r8
	cmp r0, #2
	bgt _0801A4EC
	b _0801A3E4
_0801A4EC:
	ldrh r0, [r6, #6]
	cmp r0, #0x1f
	bls _0801A514
	adds r4, r6, #0
	adds r4, #0x18
	movs r1, #1
	movs r2, #2
	mov r8, r2
_0801A4FC:
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r7, #1
	rsbs r7, r7, #0
	add r8, r7
	adds r4, #0x28
	mov r0, r8
	cmp r0, #0
	bge _0801A4FC
	movs r0, #0
	strb r0, [r6]
_0801A514:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A524: .4byte gSineTable
_0801A528: .4byte 0x085AA970
_0801A52C: .4byte 0x030046B8
_0801A530: .4byte 0x000003FF
_0801A534: .4byte 0x0203B400
