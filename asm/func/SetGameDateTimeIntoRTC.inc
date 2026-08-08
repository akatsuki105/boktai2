	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	adds r5, r3, #0
	ldr r6, [sp, #0x20]
	adds r0, #0x30
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl FUN_0823dc40
	ldr r4, _0823E5F8 @ =0x03004810
	movs r7, #0
	strb r0, [r4]
	mov r1, sb
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl FUN_0823dc40
	strb r0, [r4, #1]
	mov r1, sl
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl FUN_0823dc40
	strb r0, [r4, #2]
	mov r0, r8
	mov r1, sb
	mov r2, sl
	bl FUN_0823daa4
	strb r0, [r4, #3]
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	adds r0, r5, #0
	bl FUN_0823dc40
	strb r0, [r4, #4]
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	adds r0, r6, #0
	bl FUN_0823dc40
	strb r0, [r4, #5]
	ldr r1, [sp, #0x24]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl FUN_0823dc40
	strb r0, [r4, #6]
	strb r7, [r4, #7]
	movs r6, #0
	bl FUN_08241704
	ldr r0, _0823E5FC @ =0x04000208
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r5, _0823E600 @ =0x04000200
	b _0823E60C
	.align 2, 0
_0823E5F8: .4byte 0x03004810
_0823E5FC: .4byte 0x04000208
_0823E600: .4byte 0x04000200
_0823E604:
	movs r0, #0xc8
	bl Delay
	adds r7, #1
_0823E60C:
	cmp r7, #4
	bgt _0823E638
	mov r1, r8
	mov r0, sb
	strh r1, [r0]
	ldrh r4, [r5]
	strh r1, [r5]
	bl FUN_0823d904
	ldr r0, _0823E64C @ =0x03004810
	bl RtcWriteDate
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	bl FUN_0823d910
	strh r4, [r5]
	movs r0, #1
	mov r1, sb
	strh r0, [r1]
	cmp r6, #1
	bne _0823E604
_0823E638:
	bl FUN_0824172c
	adds r0, r6, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823E64C: .4byte 0x03004810
