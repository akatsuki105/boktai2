	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r6, #0
	adds r4, r6, #0
	adds r4, #0x48
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08032FD8
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032F54
	ldr r1, _08032F50 @ =0x00000824
	adds r0, r6, r1
	ldr r0, [r0]
	movs r3, #0xe
	cmp r0, #0
	bne _08032F64
	movs r3, #0xa
	b _08032F64
	.align 2, 0
_08032F50: .4byte 0x00000824
_08032F54:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	movs r3, #0xa
	cmp r0, #0
	beq _08032F64
	movs r3, #0xe
_08032F64:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_08022c9c
	movs r1, #0x8e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl FUN_08023090
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r6, #0
	bl FUN_08022fb8
	ldr r3, _08032FEC @ =0x00001044
	adds r0, r5, r3
	movs r2, #0
	str r2, [r0]
	ldr r0, _08032FF0 @ =0x00000854
	adds r3, r5, r0
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r3]
	str r1, [r3, #4]
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	ldr r0, _08032FF4 @ =0x00000311
	bl PlaySound_0824078c
	ldr r0, _08032FF8 @ =0x000001C5
	bl PlaySound_0824078c
	ldr r1, _08032FFC @ =0x00001050
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08032FD8
	bl FUN_0805b1a0
_08032FD8:
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08033000
	subs r0, r2, #4
	b _08033002
	.align 2, 0
_08032FEC: .4byte 0x00001044
_08032FF0: .4byte 0x00000854
_08032FF4: .4byte 0x00000311
_08032FF8: .4byte 0x000001C5
_08032FFC: .4byte 0x00001050
_08033000:
	movs r0, #0
_08033002:
	strh r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08033018
	subs r0, r2, #4
	b _0803301A
_08033018:
	movs r0, #0
_0803301A:
	strh r0, [r1]
	movs r2, #0xd
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #4
	bls _08033036
	b _08033310
_08033036:
	lsls r0, r0, #2
	ldr r1, _08033040 @ =_08033044
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08033040: .4byte _08033044
_08033044: @ jump table
	.4byte _08033058 @ case 0
	.4byte _080330B4 @ case 1
	.4byte _08033110 @ case 2
	.4byte _080331C4 @ case 3
	.4byte _080332D4 @ case 4
_08033058:
	movs r0, #8
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #3
	ands r0, r7
	cmp r0, #0
	bne _08033070
	adds r0, r5, #0
	bl FUN_0802991c
_08033070:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bhi _08033086
	b _08033310
_08033086:
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_08029cc8
	ldr r0, _080330AC @ =0x00000355
	bl PlaySound_0824078c
	ldr r0, _080330B0 @ =0x000001C5
	bl PlaySound_0824078c
	b _08033310
	.align 2, 0
_080330AC: .4byte 0x00000355
_080330B0: .4byte 0x000001C5
_080330B4:
	movs r0, #8
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #3
	ands r0, r7
	cmp r0, #0
	bne _080330CC
	adds r0, r5, #0
	bl FUN_0802991c
_080330CC:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _080330E2
	b _08033310
_080330E2:
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r3, #0x16
	bl FUN_08022da8
	b _08033310
_08033110:
	adds r0, r4, #0
	adds r0, #8
	ldr r4, _08033198 @ =0x00000854
	adds r1, r5, r4
	ldr r3, _0803319C @ =0x00000FD8
	adds r2, r5, r3
	movs r4, #0xae
	lsls r4, r4, #1
	adds r6, r5, r4
	ldrh r3, [r6]
	movs r4, #7
	str r4, [sp]
	bl FUN_08237970
	movs r0, #3
	ands r0, r7
	cmp r0, #0
	bne _0803313A
	adds r0, r5, #0
	bl FUN_0802991c
_0803313A:
	ldrh r0, [r6]
	adds r0, #1
	movs r2, #0
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x80
	bls _080331B8
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	strh r2, [r6]
	ldr r3, _080331A0 @ =0x00000FD4
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	ldr r4, _080331A4 @ =0x00000878
	adds r0, r5, r4
	strh r2, [r0]
	ldr r0, _080331A8 @ =0x0000087C
	adds r1, r5, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _080331AC @ =0x0000087A
	adds r1, r5, r2
	movs r0, #0xc1
	strh r0, [r1]
	ldr r1, _080331B0 @ =0x03003584
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _080331B4 @ =0x0000033B
	bl PlaySound_082406e0
	b _08033310
	.align 2, 0
_08033198: .4byte 0x00000854
_0803319C: .4byte 0x00000FD8
_080331A0: .4byte 0x00000FD4
_080331A4: .4byte 0x00000878
_080331A8: .4byte 0x0000087C
_080331AC: .4byte 0x0000087A
_080331B0: .4byte 0x03003584
_080331B4: .4byte 0x0000033B
_080331B8:
	movs r0, #8
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	b _08033310
_080331C4:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	cmp r0, #0x1f
	bhi _080331DA
	movs r0, #4
	movs r4, #0xc5
	lsls r4, r4, #1
	adds r1, r5, r4
	strb r0, [r1]
_080331DA:
	ldrh r0, [r2]
	cmp r0, #0x20
	bne _08033226
	movs r0, #3
	movs r2, #0xc6
	ldr r3, _08033204 @ =0x0000087C
	adds r1, r5, r3
	movs r3, #0
	strb r0, [r1]
	ldr r4, _08033208 @ =0x0000087A
	adds r0, r5, r4
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _08033210
	ldr r0, _0803320C @ =0x00000878
	adds r1, r5, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _08033226
	.align 2, 0
_08033204: .4byte 0x0000087C
_08033208: .4byte 0x0000087A
_0803320C: .4byte 0x00000878
_08033210:
	cmp r0, #0
	bne _08033220
	ldr r1, _0803321C @ =0x00000878
	adds r0, r5, r1
	b _08033224
	.align 2, 0
_0803321C: .4byte 0x00000878
_08033220:
	ldr r2, _08033264 @ =0x00000878
	adds r0, r5, r2
_08033224:
	strh r3, [r0]
_08033226:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x60
	bls _08033310
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803326C
	ldr r1, _08033268 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x49
	cmp r0, #0
	bne _0803327C
	movs r3, #0x48
	b _0803327C
	.align 2, 0
_08033264: .4byte 0x00000878
_08033268: .4byte 0x00000824
_0803326C:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x48
	cmp r0, #0
	beq _0803327C
	movs r3, #0x49
_0803327C:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r6, #0
	bl FUN_08022da8
	adds r0, r5, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _080332B0
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r3, #0x84
	lsls r3, r3, #3
	adds r0, r5, r3
	b _080332BE
_080332B0:
	ldr r0, _080332D0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r4, #0xcf
	lsls r4, r4, #2
	adds r1, r5, r4
_080332BE:
	str r0, [r1]
	adds r0, r1, #0
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r0, [r0]
	str r0, [r1]
	b _08033310
	.align 2, 0
_080332D0: .4byte 0x03003584
_080332D4:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r4, r5, r3
	ldrh r0, [r4]
	cmp r0, #0x10
	bne _080332E6
	ldr r0, _08033318 @ =0x0000033A
	bl PlaySound_082406e0
_080332E6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x80
	bls _08033310
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r4]
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r6, #0
	bl FUN_08023024
_08033310:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033318: .4byte 0x0000033A
