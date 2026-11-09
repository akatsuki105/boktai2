	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0818BC48 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818BC4C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818BC4E
	.align 2, 0
_0818BC48: .4byte 0x0000046C
_0818BC4C:
	movs r0, #0
_0818BC4E:
	cmp r0, #0
	beq _0818BCA2
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r6, _0818BCD4 @ =0x0000046D
	adds r0, r4, r6
	movs r2, #0
	strb r1, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r1, r4, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0818BCD8 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818BCDC @ =0x00000F2C
	adds r2, r5, r0
	ldr r0, _0818BCE0 @ =0xFFFF7FFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0818BCA2:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	ldr r2, _0818BCE4 @ =0x05000002
	bl CpuSet
	ldr r3, _0818BCE8 @ =0x00000484
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0xef
	ble _0818BD44
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r4, r6
	ldrb r1, [r0]
	ldrb r0, [r4, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818BCF0
	ldr r0, _0818BCEC @ =0xFFFFFF00
	adds r1, r1, r0
	b _0818BCFE
	.align 2, 0
_0818BCD4: .4byte 0x0000046D
_0818BCD8: .4byte 0x000003E5
_0818BCDC: .4byte 0x00000F2C
_0818BCE0: .4byte 0xFFFF7FFF
_0818BCE4: .4byte 0x05000002
_0818BCE8: .4byte 0x00000484
_0818BCEC: .4byte 0xFFFFFF00
_0818BCF0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818BCFE
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0818BCFE:
	movs r0, #0
	cmp r1, #0x1f
	bgt _0818BD06
	movs r0, #1
_0818BD06:
	cmp r0, #0
	beq _0818BD44
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r4, #5]
	movs r2, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	ldr r3, _0818BD3C @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r2, [r0]
	ldr r2, _0818BD40 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _0818BDE4
	.align 2, 0
_0818BD3C: .4byte 0x00000469
_0818BD40: .4byte 0x00000484
_0818BD44:
	ldr r6, _0818BD5C @ =0x00000484
	adds r0, r4, r6
	ldr r0, [r0]
	cmp r0, #0x77
	bgt _0818BD60
	movs r5, #0x50
	movs r0, #8
	mov ip, r0
	movs r6, #2
	movs r7, #0xc3
	lsls r7, r7, #5
	b _0818BD7A
	.align 2, 0
_0818BD5C: .4byte 0x00000484
_0818BD60:
	cmp r0, #0xc7
	bgt _0818BD6E
	movs r5, #0x28
	movs r1, #8
	mov ip, r1
	movs r6, #4
	b _0818BD76
_0818BD6E:
	movs r5, #0x28
	movs r2, #8
	mov ip, r2
	movs r6, #6
_0818BD76:
	movs r7, #0x9b
	lsls r7, r7, #3
_0818BD7A:
	ldr r3, _0818BD98 @ =gSineTable
	ldrb r2, [r4, #5]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0818BD9C
	asrs r0, r0, #0xc
	b _0818BDA2
	.align 2, 0
_0818BD98: .4byte gSineTable
_0818BD9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818BDA2:
	adds r1, r0, #0
	lsls r0, r2, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0818BDB6
	asrs r2, r0, #0xc
	b _0818BDBC
_0818BDB6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818BDBC:
	ldrb r0, [r4, #5]
	adds r0, r0, r6
	strb r0, [r4, #5]
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	mov r1, ip
	movs r2, #0xc
	adds r3, r7, #0
	bl FUN_0818fdd8
	ldr r3, _0818BDEC @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818BDE4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818BDEC: .4byte 0x00000484
