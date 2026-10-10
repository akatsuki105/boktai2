	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, _08238718 @ =0x04000120
	ldrh r0, [r4]
	ldr r2, _0823871C @ =0x030046D4
	movs r0, #0
	str r0, [r2]
	ldr r0, _08238720 @ =0x04000128
	ldrh r0, [r0]
	adds r1, r0, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _08238710
	movs r0, #0xb0
	ands r1, r0
	cmp r1, #0x80
	bne _08238724
_08238710:
	movs r0, #2
	rsbs r0, r0, #0
	str r0, [r2]
	b _08238996
	.align 2, 0
_08238718: .4byte 0x04000120
_0823871C: .4byte 0x030046D4
_08238720: .4byte 0x04000128
_08238724:
	movs r3, #0
	ldr r0, _082387E0 @ =0x03000828
	mov sb, r0
	ldr r0, [r0]
	movs r1, #1
	mov ip, r1
	subs r0, r1, r0
	lsls r0, r0, #3
	ldr r1, _082387E4 @ =0x03004720
	adds r6, r0, r1
	ldr r2, _082387E8 @ =0x03000830
	ldr r0, [r2]
	mov r1, ip
	subs r0, r1, r0
	lsls r0, r0, #3
	ldr r1, _082387EC @ =0x030046F0
	adds r7, r0, r1
	ldrh r0, [r4]
	adds r1, r0, #0
	mov r8, r1
	strh r1, [r7]
	movs r4, #0x80
	lsls r4, r4, #8
	ands r0, r4
	mov sl, sb
	cmp r0, #0
	bne _0823875C
	adds r3, r1, #0
_0823875C:
	ldr r0, _082387F0 @ =0x04000122
	ldrh r0, [r0]
	adds r1, r0, #0
	strh r1, [r7, #2]
	ands r0, r4
	cmp r0, #0
	bne _0823876C
	orrs r3, r1
_0823876C:
	ldr r0, _082387F4 @ =0x04000124
	ldrh r0, [r0]
	adds r1, r0, #0
	strh r1, [r7, #4]
	ands r0, r4
	cmp r0, #0
	bne _0823877C
	orrs r3, r1
_0823877C:
	ldr r0, _082387F8 @ =0x04000126
	ldrh r0, [r0]
	adds r1, r0, #0
	strh r1, [r7, #6]
	ands r0, r4
	cmp r0, #0
	bne _0823878C
	orrs r3, r1
_0823878C:
	movs r5, #0x80
	lsls r5, r5, #7
	ands r3, r5
	cmp r3, #0
	beq _08238798
	b _082388D4
_08238798:
	ldr r0, _082387FC @ =0x0300082C
	ldr r1, [r0]
	mov sb, r0
	cmp r1, #0
	beq _08238810
	ldr r0, _08238800 @ =0x03004730
	ldrh r1, [r0]
	ldr r4, _08238804 @ =0x030046E0
	ldrh r0, [r4]
	adds r1, r1, r0
	movs r0, #3
	ands r1, r0
	ldr r2, _08238808 @ =0x03004700
	lsls r3, r1, #3
	adds r0, r3, r2
	mov r6, r8
	strh r6, [r0]
	adds r0, r2, #2
	adds r0, r3, r0
	ldrh r1, [r7, #2]
	strh r1, [r0]
	adds r0, r2, #4
	adds r0, r3, r0
	ldrh r1, [r7, #4]
	strh r1, [r0]
	adds r2, #6
	adds r3, r3, r2
	ldrh r0, [r7, #6]
	strh r0, [r3]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r0, _0823880C @ =0x03000826
	strh r5, [r0]
	adds r2, r0, #0
	b _08238978
	.align 2, 0
_082387E0: .4byte 0x03000828
_082387E4: .4byte 0x03004720
_082387E8: .4byte 0x03000830
_082387EC: .4byte 0x030046F0
_082387F0: .4byte 0x04000122
_082387F4: .4byte 0x04000124
_082387F8: .4byte 0x04000126
_082387FC: .4byte 0x0300082C
_08238800: .4byte 0x03004730
_08238804: .4byte 0x030046E0
_08238808: .4byte 0x03004700
_0823880C: .4byte 0x03000826
_08238810:
	ldr r0, _08238890 @ =0x030046E0
	mov ip, r0
	ldrh r0, [r0]
	cmp r0, #0
	beq _0823889C
	ldr r2, _08238894 @ =0x03004700
	ldr r1, _08238898 @ =0x03004730
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r6]
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r5, r2, #2
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r6, #2]
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r4, r2, #4
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r6, #4]
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r3, r2, #6
	mov r8, r3
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r6, #6]
	ldrh r0, [r1]
	adds r0, #1
	movs r3, #3
	ands r0, r3
	strh r0, [r1]
	mov r6, ip
	ldrh r0, [r6]
	mov r6, sp
	strh r0, [r6]
	subs r0, #1
	mov r6, ip
	strh r0, [r6]
	ldrh r1, [r1]
	ldrh r0, [r6]
	adds r1, r1, r0
	ands r1, r3
	lsls r1, r1, #3
	adds r2, r1, r2
	ldrh r0, [r7]
	strh r0, [r2]
	adds r5, r1, r5
	ldrh r0, [r7, #2]
	strh r0, [r5]
	adds r4, r1, r4
	ldrh r0, [r7, #4]
	strh r0, [r4]
	add r1, r8
	ldrh r0, [r7, #6]
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r6]
	b _082388AC
	.align 2, 0
_08238890: .4byte 0x030046E0
_08238894: .4byte 0x03004700
_08238898: .4byte 0x03004730
_0823889C:
	mov r1, r8
	strh r1, [r6]
	ldrh r0, [r7, #2]
	strh r0, [r6, #2]
	ldrh r0, [r7, #4]
	strh r0, [r6, #4]
	ldrh r0, [r7, #6]
	strh r0, [r6, #6]
_082388AC:
	ldr r2, _082388CC @ =0x03000826
	ldr r1, _082388D0 @ =0x03000824
	ldrh r0, [r1]
	strh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	strh r0, [r1]
	mov r6, sl
	ldr r0, [r6]
	movs r1, #1
	subs r0, r1, r0
	str r0, [r6]
	mov r0, sb
	str r1, [r0]
	b _08238978
	.align 2, 0
_082388CC: .4byte 0x03000826
_082388D0: .4byte 0x03000824
_082388D4:
	ldr r7, _08238948 @ =0x0300082C
	ldr r0, [r7]
	cmp r0, #0
	bne _08238960
	ldr r4, _0823894C @ =0x030046E0
	ldrh r0, [r4]
	cmp r0, #0
	beq _08238960
	ldr r2, _08238950 @ =0x03004700
	ldr r3, _08238954 @ =0x03004730
	ldrh r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r6]
	ldrh r0, [r3]
	lsls r0, r0, #3
	adds r1, r2, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r6, #2]
	ldrh r0, [r3]
	lsls r0, r0, #3
	adds r1, r2, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r6, #4]
	ldrh r0, [r3]
	lsls r0, r0, #3
	adds r2, #6
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r6, #6]
	ldrh r0, [r3]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strh r0, [r3]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	ldr r2, _08238958 @ =0x03000826
	ldrh r1, [r2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0823893A
	ldr r1, _0823895C @ =0x03000824
	ldrh r0, [r1]
	strh r0, [r2]
	strh r5, [r1]
_0823893A:
	mov r1, sb
	ldr r0, [r1]
	mov r3, ip
	subs r0, r3, r0
	str r0, [r1]
	str r3, [r7]
	b _08238978
	.align 2, 0
_08238948: .4byte 0x0300082C
_0823894C: .4byte 0x030046E0
_08238950: .4byte 0x03004700
_08238954: .4byte 0x03004730
_08238958: .4byte 0x03000826
_0823895C: .4byte 0x03000824
_08238960:
	ldr r2, _082389AC @ =0x03000826
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08238978
	ldr r1, _082389B0 @ =0x03000824
	ldrh r0, [r1]
	strh r0, [r2]
	strh r3, [r1]
_08238978:
	ldr r1, _082389B4 @ =0x0400012A
	ldrh r0, [r2]
	strh r0, [r1]
	ldr r2, _082389B8 @ =0x030046CC
	ldr r0, _082389BC @ =0x04000128
	ldrh r0, [r0]
	lsrs r0, r0, #4
	movs r1, #3
	ands r0, r1
	str r0, [r2]
	ldr r6, _082389C0 @ =0x03000830
	ldr r1, [r6]
	movs r0, #1
	subs r0, r0, r1
	str r0, [r6]
_08238996:
	ldr r1, _082389C4 @ =0x03007FF8
	movs r0, #0x80
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082389AC: .4byte 0x03000826
_082389B0: .4byte 0x03000824
_082389B4: .4byte 0x0400012A
_082389B8: .4byte 0x030046CC
_082389BC: .4byte 0x04000128
_082389C0: .4byte 0x03000830
_082389C4: .4byte 0x03007FF8
