	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _0810C8FC @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810C900
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810C902
	.align 2, 0
_0810C8FC: .4byte 0x0000046D
_0810C900:
	movs r0, #0
_0810C902:
	cmp r0, #0
	beq _0810C950
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0810C934
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r3, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _0810C92E
	movs r0, #1
	b _0810C930
_0810C92E:
	movs r0, #0
_0810C930:
	cmp r0, #0
	beq _0810C93E
_0810C934:
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _0810C950
_0810C93E:
	adds r0, r4, #0
	movs r1, #0xc
	bl Enemy_PlayAnim
	movs r0, #0x80
	lsls r0, r0, #6
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0810C950:
	cmp r6, #0x3c
	bgt _0810C956
	b _0810CA84
_0810C956:
	ldr r1, _0810C9EC @ =0x0000046B
	adds r0, r4, r1
	movs r6, #0
	movs r7, #1
	strb r7, [r0]
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0810CA04
	ldr r3, _0810C9F0 @ =0x000004A4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl Enemy_SetAngleToward
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r3, _0810C9F4 @ =0x0000046D
	adds r0, r4, r3
	strb r7, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	strh r6, [r0]
	movs r2, #0xc
	subs r3, #0xeb
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0810C9F8 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0810C9FC @ =0x00000484
	adds r0, r4, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r0, #4
	ldr r1, _0810CA00 @ =0x00000222
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _0810CA7C
	.align 2, 0
_0810C9EC: .4byte 0x0000046B
_0810C9F0: .4byte 0x000004A4
_0810C9F4: .4byte 0x0000046D
_0810C9F8: .4byte 0x0000046A
_0810C9FC: .4byte 0x00000484
_0810CA00: .4byte 0x00000222
_0810CA04:
	ldr r3, _0810CA8C @ =0x000004A4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl Enemy_SetAngleToward
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _0810CA90 @ =0x0000046D
	adds r0, r4, r2
	strb r7, [r0]
	ldr r3, _0810CA94 @ =0x0000046B
	adds r0, r4, r3
	strb r5, [r0]
	adds r2, #0xe6
	adds r0, r4, r2
	strb r7, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r5, [r0]
	movs r2, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0810CA98 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0810CA9C @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0810CA7C:
	ldr r2, _0810CAA0 @ =0x00000482
	adds r1, r4, r2
	movs r0, #2
	strh r0, [r1]
_0810CA84:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810CA8C: .4byte 0x000004A4
_0810CA90: .4byte 0x0000046D
_0810CA94: .4byte 0x0000046B
_0810CA98: .4byte 0x0000046A
_0810CA9C: .4byte 0x00000484
_0810CAA0: .4byte 0x00000482
