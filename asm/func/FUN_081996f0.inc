	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r5]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _0819980C @ =0xFFFF0000
	adds r2, r3, #0
	ldr r1, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	movs r0, #0xa7
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r5, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r4, _08199810 @ =0x0000FFFF
	ands r4, r2
	orrs r4, r0
	str r4, [sp]
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r5, #4]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	adds r2, #0x35
	adds r0, r6, r2
	ldrb r0, [r0]
	ldrb r3, [r6, #6]
	adds r0, r0, r3
	strb r0, [r6, #6]
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r5, r6, r3
	ldr r0, [r5]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r2, r6, r1
	mov r3, sp
	ldrh r1, [r3]
	ldrh r2, [r2]
	adds r1, r1, r2
	adds r1, r1, r0
	strh r1, [r6, #0x1c]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	movs r3, #0x9b
	lsls r3, r3, #1
	adds r1, r6, r3
	asrs r4, r4, #0x10
	ldrh r1, [r1]
	adds r4, r4, r1
	adds r4, r4, r0
	strh r4, [r6, #0x1e]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r2, r6, r3
	mov r3, sp
	ldrh r1, [r3, #4]
	ldrh r2, [r2]
	adds r1, r1, r2
	adds r1, r1, r0
	strh r1, [r6, #0x20]
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
	cmp r0, #0x64
	ble _08199802
	ldr r0, _08199814 @ =0x00000183
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x80
	strb r1, [r6, #6]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08199818 @ =0x00000117
	adds r1, r6, r3
	strb r0, [r1]
	ldr r1, _0819981C @ =0x00000111
	adds r2, r6, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r0, _08199820 @ =FUN_08199c38
	str r0, [r1]
_08199802:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819980C: .4byte 0xFFFF0000
_08199810: .4byte 0x0000FFFF
_08199814: .4byte 0x00000183
_08199818: .4byte 0x00000117
_0819981C: .4byte 0x00000111
_08199820: .4byte FUN_08199c38
