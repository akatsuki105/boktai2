	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl FUN_08241704
	movs r7, #0
	ldr r0, _0823E66C @ =0x04000208
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r6, _0823E670 @ =0x04000200
	b _0823E67C
	.align 2, 0
_0823E66C: .4byte 0x04000208
_0823E670: .4byte 0x04000200
_0823E674:
	movs r0, #0xc8
	bl Delay
	adds r7, #1
_0823E67C:
	cmp r7, #4
	bgt _0823E6A8
	mov r1, r8
	mov r0, sb
	strh r1, [r0]
	ldrh r4, [r6]
	strh r1, [r6]
	bl FUN_0823d904
	ldr r0, _0823E764 @ =0x03004810
	bl RtcReadDate
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl FUN_0823d910
	strh r4, [r6]
	movs r0, #1
	mov r1, sb
	strh r0, [r1]
	cmp r5, #1
	bne _0823E674
_0823E6A8:
	bl FUN_0824172c
	cmp r5, #1
	bne _0823E754
	ldr r1, _0823E764 @ =0x03004810
	ldrb r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0x9f
	bhi _0823E6C4
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E6CC
_0823E6C4:
	movs r5, #2
	rsbs r5, r5, #0
	movs r0, #0
	strb r0, [r1]
_0823E6CC:
	ldrb r2, [r1, #1]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x11
	bhi _0823E6E0
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E6E8
_0823E6E0:
	movs r5, #3
	rsbs r5, r5, #0
	movs r0, #1
	strb r0, [r1, #1]
_0823E6E8:
	ldrb r2, [r1, #2]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x30
	bhi _0823E6FC
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E704
_0823E6FC:
	movs r5, #4
	rsbs r5, r5, #0
	movs r0, #1
	strb r0, [r1, #2]
_0823E704:
	ldrb r0, [r1, #3]
	cmp r0, #7
	bne _0823E712
	movs r5, #5
	rsbs r5, r5, #0
	movs r0, #0
	strb r0, [r1, #3]
_0823E712:
	ldrb r2, [r1, #4]
	cmp r2, #0x23
	bhi _0823E720
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E728
_0823E720:
	movs r5, #6
	rsbs r5, r5, #0
	movs r0, #0
	strb r0, [r1, #4]
_0823E728:
	ldrb r2, [r1, #5]
	cmp r2, #0x5f
	bhi _0823E736
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E73E
_0823E736:
	movs r5, #7
	rsbs r5, r5, #0
	movs r0, #0
	strb r0, [r1, #5]
_0823E73E:
	ldrb r2, [r1, #6]
	cmp r2, #0x5f
	bhi _0823E74C
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E754
_0823E74C:
	movs r5, #8
	rsbs r5, r5, #0
	movs r0, #0
	strb r0, [r1, #6]
_0823E754:
	adds r0, r5, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823E764: .4byte 0x03004810
