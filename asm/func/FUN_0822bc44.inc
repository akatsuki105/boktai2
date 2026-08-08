	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r2
	mov sl, r3
	ldr r4, [sp, #0x3c]
	mov r3, sp
	adds r2, r1, #0
	ldm r2!, {r5, r6, r7}
	stm r3!, {r5, r6, r7}
	ldm r2!, {r5, r6, r7}
	stm r3!, {r5, r6, r7}
	ldr r2, [sp, #0xc]
	adds r2, r2, r1
	str r2, [sp, #0xc]
	ldr r2, [sp, #0x10]
	adds r2, r2, r1
	str r2, [sp, #0x10]
	ldr r2, [sp, #0x14]
	adds r2, r2, r1
	str r2, [sp, #0x14]
	lsls r4, r4, #5
	cmp r0, #0
	bne _0822BC7E
	movs r4, #0x80
	lsls r4, r4, #8
_0822BC7E:
	adds r7, r4, #0
	movs r6, #0
	cmp r6, sb
	bge _0822BCDA
_0822BC86:
	lsls r0, r6, #1
	add r0, sl
	ldrh r1, [r0]
	mov r0, sp
	bl FUN_0822bc18
	adds r4, r0, #0
	ldr r1, [r4, #4]
	ldr r0, [sp, #0x10]
	adds r2, r1, r0
	movs r5, #0
	adds r6, #1
	str r6, [sp, #0x18]
	ldrh r0, [r4, #2]
	cmp r5, r0
	bge _0822BCD4
	movs r6, #0xc0
	lsls r6, r6, #0x13
	mov r8, r6
	ldr r3, _0822BCEC @ =0x040000D4
	ldr r0, _0822BCF0 @ =0x84000008
	mov ip, r0
_0822BCB2:
	ldrh r0, [r2]
	lsls r0, r0, #5
	ldr r1, [sp, #0x14]
	adds r1, r1, r0
	mov r6, r8
	adds r0, r7, r6
	str r1, [r3]
	str r0, [r3, #4]
	mov r0, ip
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	adds r2, #2
	adds r7, #0x20
	adds r5, #1
	ldrh r6, [r4, #2]
	cmp r5, r6
	blt _0822BCB2
_0822BCD4:
	ldr r6, [sp, #0x18]
	cmp r6, sb
	blt _0822BC86
_0822BCDA:
	movs r0, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0822BCEC: .4byte 0x040000D4
_0822BCF0: .4byte 0x84000008
