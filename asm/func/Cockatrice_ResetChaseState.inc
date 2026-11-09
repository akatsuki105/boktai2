	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r3, [r0]
	ldr r1, _0815CB68 @ =0x00000482
	adds r0, r6, r1
	movs r5, #0
	movs r1, #1
	mov ip, r1
	mov r1, ip
	strh r1, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r1, _0815CB6C @ =0xFBFFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r7, r6, r1
	ldr r0, _0815CB70 @ =0xFEFFFFFF
	mov r8, r0
	ldr r0, [r7]
	mov r1, r8
	ands r0, r1
	str r0, [r7]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r1, _0815CB74 @ =0xFFFFFF00
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0815CB78 @ =0x000006DC
	adds r0, r3, r1
	strh r5, [r0]
	adds r1, #0xc
	adds r0, r3, r1
	strh r5, [r0]
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r3, r3, r0
	strh r5, [r3]
	ldr r1, _0815CB68 @ =0x00000482
	adds r0, r6, r1
	mov r1, ip
	strh r1, [r0]
	ldr r1, _0815CB7C @ =0x00000222
	adds r0, r6, r1
	strh r5, [r0]
	adds r1, #0x2c
	adds r0, r6, r1
	strh r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _0815CB80 @ =0xFFFFFC7F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0815CB84 @ =0xF3FFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _0815CB4E
	ldr r0, [r7]
	mov r1, r8
	ands r0, r1
	str r0, [r7]
	ldr r0, _0815CB88 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x87
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0815CB8C @ =0x0000021E
	adds r0, r6, r1
	strh r5, [r0]
	subs r1, #0x1c
	adds r0, r6, r1
	strh r5, [r0]
_0815CB4E:
	ldr r0, _0815CB90 @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0815CB94 @ =0x00000542
	adds r1, r6, r0
	movs r0, #0xff
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815CB68: .4byte 0x00000482
_0815CB6C: .4byte 0xFBFFFFFF
_0815CB70: .4byte 0xFEFFFFFF
_0815CB74: .4byte 0xFFFFFF00
_0815CB78: .4byte 0x000006DC
_0815CB7C: .4byte 0x00000222
_0815CB80: .4byte 0xFFFFFC7F
_0815CB84: .4byte 0xF3FFFFFF
_0815CB88: .4byte 0xFFFFFDFF
_0815CB8C: .4byte 0x0000021E
_0815CB90: .4byte 0xFFFFFBFF
_0815CB94: .4byte 0x00000542
