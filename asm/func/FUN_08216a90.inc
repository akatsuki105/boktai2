	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r0
	ldr r1, _08216AF0 @ =0x082527E0
	add r0, sp, #4
	movs r2, #8
	bl memcpy
	add r6, sp, #0xc
	ldr r1, _08216AF4 @ =0x082527E8
	adds r0, r6, #0
	movs r2, #8
	bl memcpy
	ldr r4, _08216AF8 @ =0x0000166C
	add r4, r8
	ldr r5, _08216AFC @ =0x00001FE4
	add r5, r8
	ldrh r1, [r5]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0x3b
	bgt _08216B24
	movs r1, #5
	bl Mod
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0x1d
	bgt _08216B00
	movs r1, #5
	bl Div
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	add r1, sp
	adds r1, #4
	ldrb r1, [r1]
	strh r1, [r4, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r6, r0
	ldrb r0, [r0]
	b _08216B84
	.align 2, 0
_08216AF0: .4byte 0x082527E0
_08216AF4: .4byte 0x082527E8
_08216AF8: .4byte 0x0000166C
_08216AFC: .4byte 0x00001FE4
_08216B00:
	movs r2, #0
	ldrsh r0, [r5, r2]
	subs r0, #0x1e
	movs r1, #5
	bl Div
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	add r1, sp
	adds r1, #4
	ldrb r1, [r1]
	adds r1, #0x58
	strh r1, [r4, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r6, r0
	ldrb r0, [r0]
	b _08216B84
_08216B24:
	adds r0, r1, #0
	subs r0, #0x3c
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bhi _08216B86
	lsls r0, r0, #2
	ldr r1, _08216B3C @ =_08216B40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08216B3C: .4byte _08216B40
_08216B40: @ jump table
	.4byte _08216B58 @ case 0
	.4byte _08216B5E @ case 1
	.4byte _08216B68 @ case 2
	.4byte _08216B70 @ case 3
	.4byte _08216B78 @ case 4
	.4byte _08216B80 @ case 5
_08216B58:
	movs r1, #0
	movs r0, #0xb0
	b _08216B62
_08216B5E:
	movs r1, #0
	movs r0, #0xc0
_08216B62:
	strh r0, [r4, #0x20]
	strh r1, [r4, #0x22]
	b _08216B86
_08216B68:
	movs r0, #0xb0
	strh r0, [r4, #0x20]
	movs r0, #0x10
	b _08216B84
_08216B70:
	movs r0, #0xc0
	strh r0, [r4, #0x20]
	movs r0, #0x10
	b _08216B84
_08216B78:
	movs r0, #0xb0
	strh r0, [r4, #0x20]
	movs r0, #0x20
	b _08216B84
_08216B80:
	movs r0, #0
	strh r0, [r4, #0x20]
_08216B84:
	strh r0, [r4, #0x22]
_08216B86:
	ldr r1, _08216BA8 @ =0x00000978
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0x41
	bne _08216BAC
	mov r1, r8
	adds r1, #0x18
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #9
	movs r3, #1
	bl FUN_082370cc
	b _08216BC4
	.align 2, 0
_08216BA8: .4byte 0x00000978
_08216BAC:
	ldrh r0, [r4, #0x22]
	adds r0, #0x20
	strh r0, [r4, #0x22]
	mov r1, r8
	adds r1, #0x18
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_082370cc
_08216BC4:
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
