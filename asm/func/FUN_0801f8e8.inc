	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r2, #0
	str r3, [sp]
	ldr r0, [sp, #0x24]
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	ldr r4, [sp, #0x44]
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov sl, r4
	ldrh r1, [r5, #0x1a]
	ldr r0, [r5, #0x30]
	cmp r1, r0
	bge _0801F9A4
	ldr r0, _0801F9AC @ =0x0000042C
	adds r2, r5, r0
	movs r0, #0x8c
	muls r1, r0, r1
	ldr r0, [r2]
	adds r4, r0, r1
	movs r2, #0
	movs r3, #0
	strh r7, [r4, #0x34]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x68]
	str r1, [r4, #0x6c]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x78]
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x36
	mov r1, ip
	strb r1, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
	adds r0, #1
	mov r1, sb
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r7, r4, #0
	adds r7, #0x40
	ldr r0, [sp, #0x30]
	strb r0, [r7]
	adds r1, r4, #0
	adds r1, #0x88
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	ldr r0, [sp, #0x38]
	str r0, [r4, #0x48]
	subs r1, #0x47
	ldr r0, [sp, #0x3c]
	strb r0, [r1]
	ldr r0, [sp]
	str r0, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0x80
	strh r3, [r0]
	adds r0, r6, #0
	bl FUN_08241574
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x44
	mov r1, sl
	strb r1, [r0]
	movs r0, #0x10
	bl Malloc
	str r0, [r4, #0x2c]
	cmp r0, #0
	bne _0801F9B0
_0801F9A4:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FA98
	.align 2, 0
_0801F9AC: .4byte 0x0000042C
_0801F9B0:
	movs r1, #0x10
	bl ClearMemory
	ldrb r1, [r7]
	cmp r1, #0x10
	bhi _0801FA76
	lsls r0, r1, #2
	ldr r1, _0801F9C8 @ =_0801F9CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801F9C8: .4byte _0801F9CC
_0801F9CC: @ jump table
	.4byte _0801FA64 @ case 0
	.4byte _0801FA10 @ case 1
	.4byte _0801FA1A @ case 2
	.4byte _0801FA64 @ case 3
	.4byte _0801FA64 @ case 4
	.4byte _0801FA64 @ case 5
	.4byte _0801FA64 @ case 6
	.4byte _0801FA64 @ case 7
	.4byte _0801FA22 @ case 8
	.4byte _0801FA2A @ case 9
	.4byte _0801FA32 @ case 10
	.4byte _0801FA3A @ case 11
	.4byte _0801FA42 @ case 12
	.4byte _0801FA4A @ case 13
	.4byte _0801FA52 @ case 14
	.4byte _0801FA64 @ case 15
	.4byte _0801FA6E @ case 16
_0801FA10:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080207b0
	b _0801FA76
_0801FA1A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #0
	b _0801FA58
_0801FA22:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #1
	b _0801FA58
_0801FA2A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #2
	b _0801FA58
_0801FA32:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #3
	b _0801FA58
_0801FA3A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #4
	b _0801FA58
_0801FA42:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #5
	b _0801FA58
_0801FA4A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #6
	b _0801FA58
_0801FA52:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #7
_0801FA58:
	strb r0, [r1]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08020d44
	b _0801FA76
_0801FA64:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080203a4
	b _0801FA76
_0801FA6E:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08020d44
_0801FA76:
	ldr r1, [r4, #0x48]
	cmp r1, #0
	beq _0801FA90
	ldr r6, [sp, #0x40]
	adds r3, r4, #0
	adds r3, #0x50
	movs r2, #3
_0801FA84:
	ldm r6!, {r1}
	stm r3!, {r1}
	subs r2, #1
	cmp r2, #0
	bge _0801FA84
	b _0801FA92
_0801FA90:
	str r1, [r4, #0x50]
_0801FA92:
	ldrh r1, [r5, #0x1a]
	adds r1, #1
	strh r1, [r5, #0x1a]
_0801FA98:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
