	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, [sp, #0x20]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r5, _0822BBF4 @ =0x03003EB0
	strh r0, [r5]
	ldr r0, _0822BBF8 @ =0x03003E88
	strh r1, [r0]
	ldr r6, _0822BBFC @ =0x03003E50
	strh r2, [r6]
	ldr r1, _0822BC00 @ =0x03003EB4
	mov sl, r1
	strh r3, [r1]
	ldr r2, _0822BC04 @ =0x03003E9C
	mov sb, r2
	strh r4, [r2]
	ldr r4, _0822BC08 @ =0x085B0A08
	mov r8, r4
	ldrh r0, [r6]
	adds r0, #0x40
	movs r7, #0xff
	ands r0, r7
	lsls r0, r0, #1
	add r0, r8
	ldrh r4, [r0]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x14
	movs r0, #0x80
	lsls r0, r0, #9
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r1, r3, #0
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r4, r0, r4
	adds r0, r4, #0
	cmp r4, #0
	bge _0822BAFE
	adds r0, #0xff
_0822BAFE:
	lsrs r0, r0, #8
	ldr r5, _0822BC0C @ =0x03003E70
	strh r0, [r5]
	ldrh r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	ldrh r4, [r0]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x14
	movs r0, #0x80
	lsls r0, r0, #9
	mov r2, sl
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r4, r0, r4
	adds r0, r4, #0
	cmp r4, #0
	bge _0822BB30
	adds r0, #0xff
_0822BB30:
	lsrs r0, r0, #8
	strh r0, [r5, #2]
	ldrh r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r4, [r0, r1]
	rsbs r4, r4, #0
	asrs r4, r4, #4
	movs r0, #0x80
	lsls r0, r0, #9
	mov r2, sb
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r4, r0, r4
	adds r0, r4, #0
	cmp r4, #0
	bge _0822BB62
	adds r0, #0xff
_0822BB62:
	lsrs r0, r0, #8
	strh r0, [r5, #4]
	ldrh r0, [r6]
	adds r0, #0x40
	ands r0, r7
	lsls r0, r0, #1
	add r0, r8
	ldrh r4, [r0]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x14
	movs r0, #0x80
	lsls r0, r0, #9
	mov r2, sb
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r4, #0
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r1, #0
	bge _0822BB94
	adds r0, #0xff
_0822BB94:
	lsrs r0, r0, #8
	strh r0, [r5, #6]
	ldr r4, _0822BC10 @ =0x03003E98
	ldr r0, _0822BBF4 @ =0x03003EB0
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0x78
	subs r1, r3, r1
	lsls r1, r1, #8
	movs r0, #0
	ldrsh r2, [r5, r0]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #3
	subs r1, r1, r0
	movs r0, #2
	ldrsh r2, [r5, r0]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	subs r1, r1, r0
	str r1, [r4]
	ldr r2, _0822BC14 @ =0x03003EA0
	ldr r1, _0822BBF8 @ =0x03003E88
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r3, r3, r0
	lsls r3, r3, #8
	movs r0, #4
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	subs r3, r3, r0
	movs r4, #6
	ldrsh r1, [r5, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r3, r3, r0
	str r3, [r2]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822BBF4: .4byte 0x03003EB0
_0822BBF8: .4byte 0x03003E88
_0822BBFC: .4byte 0x03003E50
_0822BC00: .4byte 0x03003EB4
_0822BC04: .4byte 0x03003E9C
_0822BC08: .4byte 0x085B0A08
_0822BC0C: .4byte 0x03003E70
_0822BC10: .4byte 0x03003E98
_0822BC14: .4byte 0x03003EA0
