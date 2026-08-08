	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r2, #0
	ldr r0, _0821BE94 @ =0x00000BCC
	adds r2, r6, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0821BE98 @ =0x00000BC4
	adds r0, r6, r1
	mov r4, sp
	adds r4, #2
	adds r1, r2, #0
	mov r2, sp
	adds r3, r4, #0
	bl FUN_0821bd5c
	ldr r3, _0821BE9C @ =0x00000BD8
	adds r2, r6, r3
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #8
	str r0, [r2]
	ldr r0, _0821BEA0 @ =0x00000BE4
	adds r1, r6, r0
	ldrh r0, [r4]
	lsls r0, r0, #8
	str r0, [r1]
	adds r3, #0x14
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0821BEA4 @ =0x00000BEE
	adds r0, r6, r1
	strh r5, [r0]
	subs r3, #0x18
	adds r0, r6, r3
	ldr r1, [r2]
	ldr r0, [r0]
	subs r2, r1, r0
	adds r1, r2, #0
	cmp r2, #0
	bge _0821BE80
	rsbs r1, r2, #0
_0821BE80:
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r1, r0
	ble _0821BEBA
	cmp r2, #0
	bge _0821BEA8
	movs r0, #0x80
	lsls r0, r0, #9
	adds r2, r2, r0
	b _0821BEAC
	.align 2, 0
_0821BE94: .4byte 0x00000BCC
_0821BE98: .4byte 0x00000BC4
_0821BE9C: .4byte 0x00000BD8
_0821BEA0: .4byte 0x00000BE4
_0821BEA4: .4byte 0x00000BEE
_0821BEA8:
	ldr r1, _0821BEDC @ =0xFFFF0000
	adds r2, r2, r1
_0821BEAC:
	ldr r3, _0821BEE0 @ =0x00000BD8
	adds r1, r6, r3
	subs r3, #4
	adds r0, r6, r3
	ldr r0, [r0]
	adds r0, r0, r2
	str r0, [r1]
_0821BEBA:
	ldr r0, _0821BEE4 @ =0x00000BDC
	adds r1, r6, r0
	ldr r2, _0821BEE8 @ =0x00000BD4
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r3, _0821BEEC @ =0x00000BE8
	adds r1, r6, r3
	adds r2, #0xc
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0821BEDC: .4byte 0xFFFF0000
_0821BEE0: .4byte 0x00000BD8
_0821BEE4: .4byte 0x00000BDC
_0821BEE8: .4byte 0x00000BD4
_0821BEEC: .4byte 0x00000BE8
