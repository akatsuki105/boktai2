	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _081441FC
	ldr r0, _08144204 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _081441FC
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r3, _08144208 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r4, _0814420C @ =0x0000046D
	adds r0, r5, r4
	movs r4, #1
	strb r4, [r0]
	ldr r7, _08144210 @ =0x0000046B
	adds r0, r5, r7
	strb r6, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r1, #0
	strh r6, [r0]
	movs r3, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08144214 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r7, #0x1b
	adds r0, r5, r7
	str r6, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r2, r2, r4
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r1, r5, r7
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081441FC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08144204: .4byte 0x03002BE0
_08144208: .4byte Enemy_ClearStateBegun
_0814420C: .4byte 0x0000046D
_08144210: .4byte 0x0000046B
_08144214: .4byte 0x0000046A
