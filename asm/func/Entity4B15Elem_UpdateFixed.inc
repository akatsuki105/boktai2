	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r6, r1, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	beq _08019D26
	movs r0, #0
	strb r0, [r6, #2]
	movs r0, #1
	b _08019D28
_08019D26:
	movs r0, #0
_08019D28:
	cmp r0, #0
	bne _08019D2E
	b _08019E56
_08019D2E:
	mov r5, sp
	adds r7, r6, #0
	adds r7, #0x30
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019D50
	asrs r0, r0, #8
	b _08019D56
_08019D50:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D56:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019D68
	asrs r0, r0, #8
	b _08019D6E
_08019D68:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D6E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019D82
	asrs r0, r0, #8
	b _08019D88
_08019D82:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D88:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019E2C @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	mov r5, r8
	adds r5, #0x18
	mov r4, sp
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x18
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r4, r2]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #1]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r3, r8
	movs r1, #0x18
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	movs r4, #4
	ldrsh r1, [r5, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08019E30 @ =0x00000FFF
	cmp r1, r0
	bhi _08019DF6
	b _08019F08
_08019DF6:
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019E02
	b _08019F08
_08019E02:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019E34 @ =gSineTable
	ldrb r3, [r6, #1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019E38
	asrs r0, r0, #0xc
	b _08019E3E
	.align 2, 0
_08019E2C: .4byte 0x030047C8
_08019E30: .4byte 0x00000FFF
_08019E34: .4byte gSineTable
_08019E38:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019E3E:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019E54
	b _08019F66
_08019E54:
	b _08019F6A
_08019E56:
	add r5, sp, #8
	adds r7, r6, #0
	adds r7, #0x30
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov ip, r5
	cmp r0, #0
	blt _08019E7A
	asrs r0, r0, #8
	b _08019E80
_08019E7A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019E80:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019E92
	asrs r0, r0, #8
	b _08019E98
_08019E92:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019E98:
	adds r4, r0, #0
	movs r3, #2
	ldrsh r1, [r7, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019EAC
	asrs r0, r0, #8
	b _08019EB2
_08019EAC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019EB2:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019F14 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	add r0, sp, #8
	movs r4, #0
	ldrsh r2, [r0, r4]
	mov r1, r8
	movs r3, #0x18
	ldrsh r0, [r1, r3]
	subs r2, r2, r0
	mov r4, ip
	movs r1, #4
	ldrsh r0, [r4, r1]
	mov r3, r8
	movs r4, #0x1c
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08019F18 @ =0x00000FFF
	cmp r1, r0
	bls _08019F08
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019F1C
_08019F08:
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #8]
	b _08019F80
	.align 2, 0
_08019F14: .4byte 0x030047C8
_08019F18: .4byte 0x00000FFF
_08019F1C:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019F48 @ =gSineTable
	ldrb r3, [r6, #1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019F4C
	asrs r0, r0, #0xc
	b _08019F52
	.align 2, 0
_08019F48: .4byte gSineTable
_08019F4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019F52:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019F6A
_08019F66:
	asrs r0, r0, #0xc
	b _08019F70
_08019F6A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019F70:
	adds r0, #0x50
	movs r1, #0
	strh r0, [r6, #0x22]
	strh r1, [r6, #0x24]
	ldrb r1, [r6, #1]
	movs r0, #0xa0
	subs r0, r0, r1
	strb r0, [r6, #0xf]
_08019F80:
	ldr r0, [r6, #4]
	cmp r0, #0x3b
	bls _08019F90
	movs r0, #0
	strb r0, [r6]
	str r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #2]
_08019F90:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
