	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r3, _0822B40C @ =0x02039000
	lsls r0, r0, #5
	ldr r1, _0822B410 @ =0x06010000
	adds r4, r0, r1
	movs r2, #0
	ldr r0, _0822B414 @ =0x030035A4
	ldr r1, [r0]
	mov sl, r0
	cmp r2, r1
	bhs _0822B3F4
	mov sb, r1
_0822B3AE:
	ldr r1, [r3]
	movs r5, #0
	adds r2, #1
	str r2, [sp]
	adds r6, r3, #0
	adds r6, #8
	ldrh r7, [r3, #6]
	cmp r5, r7
	bge _0822B3EC
	ldr r2, _0822B418 @ =0x040000D4
	movs r0, #0x84
	lsls r0, r0, #0x18
	mov r8, r0
	movs r7, #0x80
	lsls r7, r7, #2
	mov ip, r7
_0822B3CE:
	str r1, [r2]
	str r4, [r2, #4]
	ldrh r0, [r3, #4]
	lsrs r0, r0, #2
	mov r7, r8
	orrs r0, r7
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	add r1, ip
	ldrh r0, [r3, #4]
	adds r4, r4, r0
	adds r5, #1
	ldrh r0, [r3, #6]
	cmp r5, r0
	blt _0822B3CE
_0822B3EC:
	ldr r2, [sp]
	adds r3, r6, #0
	cmp r2, sb
	blo _0822B3AE
_0822B3F4:
	movs r0, #0
	mov r1, sl
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822B40C: .4byte 0x02039000
_0822B410: .4byte 0x06010000
_0822B414: .4byte 0x030035A4
_0822B418: .4byte 0x040000D4
