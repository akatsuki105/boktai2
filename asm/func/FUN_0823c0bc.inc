	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x20
	movs r6, #0
	ldr r0, _0823C0D4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r5, #0
	adds r0, #0x26
	b _0823C1DE
	.align 2, 0
_0823C0D4: .4byte 0x03002B4C
_0823C0D8:
	ldr r0, _0823C108 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #5
	bhi _0823C1D4
	lsls r0, r0, #2
	ldr r1, _0823C10C @ =_0823C110
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823C108: .4byte 0x03002B4C
_0823C10C: .4byte _0823C110
_0823C110: @ jump table
	.4byte _0823C128 @ case 0
	.4byte _0823C12E @ case 1
	.4byte _0823C16C @ case 2
	.4byte _0823C1A4 @ case 3
	.4byte _0823C1AE @ case 4
	.4byte _0823C1C6 @ case 5
_0823C128:
	bl FUN_0823baa8
	b _0823C156
_0823C12E:
	ldrh r0, [r4, #8]
	ldr r3, _0823C164 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _0823C168 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	ldrh r1, [r4, #0xc]
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl FUN_0823bac8
_0823C156:
	adds r0, r5, #0
	bl FUN_0823c0a4
	adds r0, r5, #0
	bl FUN_0823c0ac
	b _0823C1D4
	.align 2, 0
_0823C164: .4byte 0xFFFF0000
_0823C168: .4byte 0x0000FFFF
_0823C16C:
	ldrh r0, [r4, #8]
	ldr r3, _0823C19C @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _0823C1A0 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #8]
	ldrh r2, [r4, #0xc]
	add r1, sp, #8
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r2, #0xe
	ldrsh r0, [r4, r2]
	bl FUN_0823bb7c
	b _0823C1BE
	.align 2, 0
_0823C19C: .4byte 0xFFFF0000
_0823C1A0: .4byte 0x0000FFFF
_0823C1A4:
	movs r3, #8
	ldrsh r0, [r4, r3]
	bl FUN_0823bc70
	b _0823C1BE
_0823C1AE:
	movs r1, #8
	ldrsh r0, [r4, r1]
	movs r2, #0xa
	ldrsh r1, [r4, r2]
	movs r3, #0xc
	ldrsh r2, [r4, r3]
	bl FUN_0823bd14
_0823C1BE:
	adds r0, r5, #0
	bl FUN_0823c0a4
	b _0823C1D4
_0823C1C6:
	movs r1, #8
	ldrsh r0, [r4, r1]
	bl FUN_0823bca8
	adds r0, r5, #0
	bl FUN_0823c0a4
_0823C1D4:
	adds r6, #1
	ldr r0, _0823C1F4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r7, #6
_0823C1DE:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0823C1EA
	b _0823C0D8
_0823C1EA:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823C1F4: .4byte 0x03002B4C
