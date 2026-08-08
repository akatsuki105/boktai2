	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r4, r0, #0
	mov sl, r2
	ldr r0, [sp, #0x64]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x34]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #0x38]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x3c]
	add r2, sp, #0x10
	adds r1, r2, #0
	mov r0, sl
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldr r0, [r2, #0xc]
	add r0, sl
	str r0, [r2, #0xc]
	ldr r0, [r2, #0x10]
	add r0, sl
	str r0, [r2, #0x10]
	ldr r0, [r2, #0x14]
	add r0, sl
	str r0, [r2, #0x14]
	cmp r4, #7
	bls _0822C102
	b _0822C2B0
_0822C102:
	lsls r0, r4, #2
	ldr r1, _0822C10C @ =_0822C110
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0822C10C: .4byte _0822C110
_0822C110: @ jump table
	.4byte _0822C130 @ case 0
	.4byte _0822C154 @ case 1
	.4byte _0822C194 @ case 2
	.4byte _0822C1AE @ case 3
	.4byte _0822C1C4 @ case 4
	.4byte _0822C200 @ case 5
	.4byte _0822C240 @ case 6
	.4byte _0822C264 @ case 7
_0822C130:
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	mov r8, r0
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, #0xff
	ldr r2, _0822C150 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	movs r1, #2
	bl FUN_0822ba50
	b _0822C2C0
	.align 2, 0
_0822C150: .4byte 0x03003E78
_0822C154:
	movs r0, #2
	str r0, [sp]
	movs r1, #0
	bl FUN_0822ba50
	ldr r1, [sp, #0x68]
	cmp r1, #2
	bne _0822C184
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r2, _0822C180 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #3
	str r0, [sp, #4]
	movs r1, #0
	bl FUN_0822ba50
	movs r2, #2
	mov r8, r2
	b _0822C188
	.align 2, 0
_0822C180: .4byte 0x03003E78
_0822C184:
	movs r3, #1
	mov r8, r3
_0822C188:
	mov r5, sp
	ldrh r0, [r5, #0x1a]
	lsls r4, r0, #5
	movs r0, #0x80
	lsls r0, r0, #3
	b _0822C256
_0822C194:
	movs r0, #3
	str r0, [sp]
	movs r1, #0
	bl FUN_0822ba50
	movs r6, #1
	mov r8, r6
	mov r1, sp
	ldrh r0, [r1, #0x1a]
	lsls r4, r0, #5
	movs r0, #0x80
	lsls r0, r0, #4
	b _0822C256
_0822C1AE:
	movs r0, #1
	str r0, [sp]
	movs r1, #0
	bl FUN_0822ba50
	movs r2, #1
	mov r8, r2
	mov r3, sp
	ldrh r0, [r3, #0x1a]
	lsls r4, r0, #5
	b _0822C252
_0822C1C4:
	movs r0, #1
	str r0, [sp]
	movs r1, #0
	bl FUN_0822ba50
	ldr r5, [sp, #0x68]
	cmp r5, #2
	bne _0822C1F4
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r2, _0822C1F0 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #3
	str r0, [sp, #4]
	movs r1, #0
	bl FUN_0822ba50
	movs r6, #2
	mov r8, r6
	b _0822C1F8
	.align 2, 0
_0822C1F0: .4byte 0x03003E78
_0822C1F4:
	movs r0, #1
	mov r8, r0
_0822C1F8:
	mov r1, sp
	ldrh r0, [r1, #0x1a]
	lsls r4, r0, #5
	b _0822C252
_0822C200:
	movs r0, #2
	str r0, [sp]
	movs r1, #0
	bl FUN_0822ba50
	ldr r2, [sp, #0x68]
	cmp r2, #2
	bne _0822C230
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _0822C22C @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	str r0, [sp, #4]
	movs r1, #0
	bl FUN_0822ba50
	movs r3, #2
	mov r8, r3
	b _0822C234
	.align 2, 0
_0822C22C: .4byte 0x03003E78
_0822C230:
	movs r5, #1
	mov r8, r5
_0822C234:
	mov r6, sp
	ldrh r0, [r6, #0x1a]
	lsls r4, r0, #5
	movs r0, #0x80
	lsls r0, r0, #3
	b _0822C256
_0822C240:
	movs r0, #1
	str r0, [sp]
	movs r1, #2
	bl FUN_0822ba50
	movs r0, #1
	mov r8, r0
	movs r4, #0x80
	lsls r4, r4, #8
_0822C252:
	movs r0, #0x80
	lsls r0, r0, #2
_0822C256:
	ldr r2, _0822C260 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _0822C2C0
	.align 2, 0
_0822C260: .4byte 0x03003E78
_0822C264:
	movs r1, #3
	mov r8, r1
	movs r0, #2
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	bl FUN_0822ba50
	movs r0, #3
	movs r1, #0
	bl FUN_0822ba50
	movs r0, #1
	movs r1, #0
	bl FUN_0822ba50
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _0822C2AC @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	strh r0, [r2]
	mov r2, sp
	ldrh r0, [r2, #0x1a]
	lsls r4, r0, #5
	b _0822C2C0
	.align 2, 0
_0822C2AC: .4byte 0x03003E78
_0822C2B0:
	movs r0, #2
	str r0, [sp]
	movs r1, #0
	bl FUN_0822ba50
	movs r3, #0
	mov r8, r3
	movs r4, #0
_0822C2C0:
	mov r5, sp
	ldrh r0, [r5, #0x16]
	cmp r0, #0
	beq _0822C2D8
	ldr r1, [sp, #0x20]
	cmp r1, sl
	beq _0822C2D8
	ldr r0, [sp]
	ldrh r3, [r5, #0x16]
	adds r2, r4, #0
	bl FUN_0822b9d4
_0822C2D8:
	movs r3, #0
	cmp r3, r8
	bge _0822C386
	mov sb, r3
_0822C2E0:
	lsls r6, r3, #2
	mov r1, sp
	adds r0, r1, r6
	ldr r7, [r0]
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #4
	ldr r1, _0822C320 @ =0x03003ED0
	adds r4, r0, r1
	ldr r5, [sp, #0x1c]
	cmp r7, #0
	bne _0822C300
	str r3, [sp, #0x40]
	bl FUN_0822e8b4
	ldr r3, [sp, #0x40]
_0822C300:
	ldr r2, [sp, #0x68]
	cmp r3, r2
	bge _0822C324
	ldr r0, [sp, #0x6c]
	cmp r0, #0
	beq _0822C324
	adds r0, r6, r0
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	add r1, sp, #0x28
	adds r0, r0, r5
	ldm r0!, {r2, r5, r6}
	stm r1!, {r2, r5, r6}
	b _0822C32E
	.align 2, 0
_0822C320: .4byte 0x03003ED0
_0822C324:
	add r1, sp, #0x28
	mov r2, sb
	adds r0, r2, r5
	ldm r0!, {r2, r5, r6}
	stm r1!, {r2, r5, r6}
_0822C32E:
	add r2, sp, #0x28
	ldr r0, [r2, #8]
	add r0, sl
	str r0, [r2, #8]
	movs r0, #0
	mov r5, sp
	ldrh r5, [r5, #0x34]
	strh r5, [r4]
	strh r7, [r4, #2]
	strh r0, [r4, #0x20]
	strh r0, [r4, #0x22]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	ldr r6, [sp, #0x38]
	lsls r1, r6, #0x10
	asrs r1, r1, #0x14
	ldr r5, [sp, #0x3c]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x14
	strh r1, [r4, #0x14]
	strh r0, [r4, #0x16]
	ldr r0, [sp, #0x24]
	str r0, [r4, #0x24]
	ldr r0, [r2, #8]
	str r0, [r4, #0x28]
	ldrh r1, [r2]
	strh r1, [r4, #0x18]
	ldrh r0, [r2, #2]
	strh r0, [r4, #0x1a]
	strh r1, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	adds r0, r7, #0
	str r3, [sp, #0x40]
	bl GetTilemapBuffer
	str r0, [r4, #0x2c]
	movs r6, #0xc
	add sb, r6
	ldr r3, [sp, #0x40]
	adds r3, #1
	cmp r3, r8
	blt _0822C2E0
_0822C386:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
