	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _0801AED8 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801AF70
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	adds r1, #0xa4
	lsls r1, r1, #0x10
	ldr r0, _0801AEDC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r6, r5, r0
	mov r7, sp
	mov r0, sp
	ldrh r0, [r0]
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
	blt _0801AEE0
	asrs r0, r0, #8
	b _0801AEE6
	.align 2, 0
_0801AED8: .4byte 0x03002BE0
_0801AEDC: .4byte 0x0000FFFF
_0801AEE0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AEE6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801AEF8
	asrs r0, r0, #8
	b _0801AEFE
_0801AEF8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AEFE:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801AF12
	asrs r0, r0, #8
	b _0801AF18
_0801AF12:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AF18:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0801AF48 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801AF4C
	movs r0, #0
	b _0801AF52
	.align 2, 0
_0801AF48: .4byte 0x030047C8
_0801AF4C:
	cmp r0, #0xf0
	ble _0801AF54
	movs r0, #0xf0
_0801AF52:
	strh r0, [r1]
_0801AF54:
	ldr r0, _0801AF64 @ =0x000002F6
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801AF68
	movs r0, #0
	b _0801AF80
	.align 2, 0
_0801AF64: .4byte 0x000002F6
_0801AF68:
	cmp r0, #0xb4
	ble _0801AF82
	movs r0, #0xb4
	b _0801AF80
_0801AF70:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	ldr r2, _0801AFDC @ =0x000002F6
	adds r1, r5, r2
	movs r0, #0x5a
_0801AF80:
	strh r0, [r1]
_0801AF82:
	ldrh r1, [r5, #0x22]
	movs r4, #1
	subs r1, r4, r1
	adds r0, r5, #0
	bl FUN_0801ad78
	ldr r2, _0801AFE0 @ =0x03003518
	ldrh r0, [r5, #0x22]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x24
	adds r0, r5, r0
	str r0, [r2]
	ldr r1, _0801AFE4 @ =0x03002CA0
	ldr r0, _0801AFE8 @ =0x04000040
	str r0, [r1]
	ldr r0, _0801AFEC @ =0x03003510
	strh r4, [r0]
	ldr r0, _0801AFF0 @ =0x03003514
	strh r4, [r0]
	ldrh r0, [r5, #0x1a]
	cmp r0, #0
	beq _0801AFF8
	ldrh r0, [r5, #0x1c]
	ldrh r1, [r5, #0x18]
	adds r0, r0, r1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	ldr r1, _0801AFF4 @ =0x0F9F0000
	cmp r0, r1
	ble _0801B01A
	movs r0, #0xfa
	lsls r0, r0, #4
	strh r0, [r5, #0x18]
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _0801B01A
	adds r0, r5, #0
	bl KillEntity
	b _0801B01A
	.align 2, 0
_0801AFDC: .4byte 0x000002F6
_0801AFE0: .4byte 0x03003518
_0801AFE4: .4byte 0x03002CA0
_0801AFE8: .4byte 0x04000040
_0801AFEC: .4byte 0x03003510
_0801AFF0: .4byte 0x03003514
_0801AFF4: .4byte 0x0F9F0000
_0801AFF8:
	ldrh r0, [r5, #0x18]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	bgt _0801B01A
	strh r1, [r5, #0x18]
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _0801B01A
	adds r0, r5, #0
	bl KillEntity
_0801B01A:
	ldrh r0, [r5, #0x22]
	movs r1, #1
	subs r1, r1, r0
	strh r1, [r5, #0x22]
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
