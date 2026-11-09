	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _081730BC @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081730C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081730C2
	.align 2, 0
_081730BC: .4byte 0x0000046C
_081730C0:
	movs r0, #0
_081730C2:
	cmp r0, #0
	beq _08173104
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _08173138 @ =0x0000046D
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _0817313C @ =0x0000046B
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
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
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r1, r4, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08173104:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	ldr r2, _08173140 @ =0x05000002
	bl CpuSet
	ldr r1, _08173144 @ =0x00000484
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0xef
	ble _081731A0
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r1, [r0]
	ldrb r0, [r4, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0817314C
	ldr r3, _08173148 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0817315A
	.align 2, 0
_08173138: .4byte 0x0000046D
_0817313C: .4byte 0x0000046B
_08173140: .4byte 0x05000002
_08173144: .4byte 0x00000484
_08173148: .4byte 0xFFFFFF00
_0817314C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0817315A
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_0817315A:
	movs r0, #0
	cmp r1, #0x1f
	bgt _08173162
	movs r0, #1
_08173162:
	cmp r0, #0
	beq _081731A0
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r4, #5]
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	ldr r5, _08173198 @ =0x00000469
	adds r0, r4, r5
	strb r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r2, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r1, [r0]
	ldr r0, _0817319C @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08173240
	.align 2, 0
_08173198: .4byte 0x00000469
_0817319C: .4byte 0x0000046C
_081731A0:
	ldr r1, _081731B8 @ =0x00000484
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0x77
	bgt _081731BC
	movs r5, #0x50
	movs r2, #8
	mov ip, r2
	movs r6, #2
	movs r7, #0xc3
	lsls r7, r7, #5
	b _081731D6
	.align 2, 0
_081731B8: .4byte 0x00000484
_081731BC:
	cmp r0, #0xc7
	bgt _081731CA
	movs r5, #0x28
	movs r3, #8
	mov ip, r3
	movs r6, #4
	b _081731D2
_081731CA:
	movs r5, #0x28
	movs r0, #8
	mov ip, r0
	movs r6, #6
_081731D2:
	movs r7, #0x9b
	lsls r7, r7, #3
_081731D6:
	ldr r3, _081731F4 @ =gSineTable
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
	blt _081731F8
	asrs r0, r0, #0xc
	b _081731FE
	.align 2, 0
_081731F4: .4byte gSineTable
_081731F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081731FE:
	adds r1, r0, #0
	lsls r0, r2, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08173212
	asrs r2, r0, #0xc
	b _08173218
_08173212:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08173218:
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
	bl FUN_08177d34
	ldr r3, _08173248 @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08173240:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08173248: .4byte 0x00000484
