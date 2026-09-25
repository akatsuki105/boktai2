	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	adds r3, r1, #0
	mov r8, r2
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #1
	add r1, ip
	b _0807F7AC
_0807F7A2:
	adds r1, #0x3c
	adds r2, #1
	cmp r2, #0xf
	ble _0807F7AC
	b _0807F8B8
_0807F7AC:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0807F7A2
	cmp r2, #0xf
	ble _0807F7B8
	b _0807F8B8
_0807F7B8:
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, #0xf8
	mov r1, ip
	adds r7, r1, r0
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x18]
	str r1, [r7, #0x1c]
	ldr r6, _0807F840 @ =0x0203B400
	ldr r5, _0807F844 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _0807F848 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	ldrh r0, [r7, #0x18]
	subs r0, #0x3f
	movs r4, #0x7f
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r7, #0x18]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ldrh r0, [r7, #0x1c]
	subs r0, #0x3f
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r0, [r7, #0x1a]
	adds r0, #0x80
	strh r0, [r7, #0x1a]
	mov r0, ip
	adds r0, #0xf4
	ldr r1, [r0]
	adds r0, r7, #0
	movs r2, #4
	bl FUN_0822dafc
	ldr r2, _0807F84C @ =0x085B0A08
	mov r0, r8
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _0807F850
	asrs r0, r0, #0xc
	b _0807F856
	.align 2, 0
_0807F840: .4byte 0x0203B400
_0807F844: .4byte 0x030046B8
_0807F848: .4byte 0x000003FF
_0807F84C: .4byte 0x085B0A08
_0807F850:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807F856:
	strh r0, [r7, #0x34]
	ldr r1, _0807F878 @ =0x085B0A08
	movs r0, #0xff
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _0807F87C
	asrs r0, r0, #0xc
	b _0807F882
	.align 2, 0
_0807F878: .4byte 0x085B0A08
_0807F87C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807F882:
	movs r1, #0
	strh r0, [r7, #0x38]
	adds r0, r7, #0
	adds r0, #0x2c
	strb r1, [r0]
	adds r0, #3
	movs r3, #1
	strb r3, [r0]
	ldr r2, _0807F8C4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0807F8C8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0807F8CC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	adds r1, r7, #0
	adds r1, #0x2e
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x28
	strb r3, [r0]
_0807F8B8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F8C4: .4byte 0x030046B8
_0807F8C8: .4byte 0x000003FF
_0807F8CC: .4byte 0x0203B400
