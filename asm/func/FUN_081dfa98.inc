	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _081DFAFC @ =0x030001AC
	movs r1, #0
	str r1, [r0]
	ldrb r1, [r4, #0x1c]
	adds r6, r0, #0
	cmp r1, #4
	bls _081DFAB0
	ldr r1, _081DFB00 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081DFAB0:
	movs r0, #1
	str r0, [r6]
	ldrb r0, [r4, #0x1c]
	adds r1, r0, #0
	cmp r1, #2
	bls _081DFB24
	ldr r0, [r4, #0x44]
	bl FUN_08238da8
	str r0, [r4, #0x4c]
	movs r0, #2
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0x42
	ldrh r0, [r0]
	bl FUN_08238e14
	str r0, [r4, #0x48]
	movs r0, #3
	str r0, [r6]
	ldrb r1, [r4, #0x1c]
	cmp r1, #5
	bls _081DFB08
	ldr r0, _081DFB04 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DFB1A
	movs r2, #0x18
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _081DFB1A
	cmp r1, #0x16
	beq _081DFB1A
	cmp r1, #0x18
	beq _081DFB1A
	bl FUN_08238d84
	b _081DFB1A
	.align 2, 0
_081DFAFC: .4byte 0x030001AC
_081DFB00: .4byte 0x030047B8
_081DFB04: .4byte 0x03002C68
_081DFB08:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _081DFB1A
	cmp r1, #0x16
	beq _081DFB1A
	cmp r1, #0x18
	beq _081DFB1A
	bl FUN_08238d84
_081DFB1A:
	ldr r1, _081DFB80 @ =0x030001AC
	movs r0, #4
	str r0, [r1]
	adds r6, r1, #0
	ldrb r1, [r4, #0x1c]
_081DFB24:
	adds r5, r6, #0
	movs r0, #5
	str r0, [r5]
	adds r3, r1, #0
	cmp r3, #4
	bls _081DFBA0
	cmp r3, #0x16
	beq _081DFBA0
	cmp r3, #0x18
	beq _081DFBA0
	cmp r3, #0x19
	beq _081DFBA0
	movs r0, #6
	str r0, [r5]
	ldr r1, [r4, #0x4c]
	subs r0, #9
	cmp r1, r0
	bne _081DFB8C
	movs r2, #1
	ldr r1, _081DFB84 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #8
	str r0, [r5]
	ldrb r0, [r4, #0x1f]
	cmp r0, #0xfe
	bhi _081DFB7A
	adds r0, #1
	strb r0, [r4, #0x1f]
	cmp r3, #4
	bls _081DFB7A
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bls _081DFB7A
	ldr r0, _081DFB88 @ =0x030047AC
	ldr r0, [r0]
	cmp r0, #0
	bne _081DFB7A
	adds r0, r4, #0
	bl FUN_081ddbdc
_081DFB7A:
	ldr r1, _081DFB80 @ =0x030001AC
	movs r0, #9
	b _081DFC0C
	.align 2, 0
_081DFB80: .4byte 0x030001AC
_081DFB84: .4byte 0x030044BC
_081DFB88: .4byte 0x030047AC
_081DFB8C:
	ldr r2, _081DFBDC @ =0x030044BC
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r4, #0x1f]
	movs r0, #0xa
	str r0, [r6]
_081DFBA0:
	ldr r5, _081DFBE0 @ =0x030001AC
	movs r0, #0xc
	str r0, [r5]
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r0, [r4, #0x34]
	adds r0, #1
	str r0, [r4, #0x34]
	movs r0, #0xe
	str r0, [r5]
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _081DFC08
	adds r0, r4, #0
	bl KillEntity
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	bne _081DFBE4
	movs r0, #0xf
	str r0, [r5]
	bl SoftReset_0823a928
	b _081DFC08
	.align 2, 0
_081DFBDC: .4byte 0x030044BC
_081DFBE0: .4byte 0x030001AC
_081DFBE4:
	ldr r2, _081DFBFC @ =0x000002E6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DFC00
	movs r0, #0x10
	str r0, [r5]
	ldrh r0, [r1]
	movs r1, #0
	bl Script_ExecById
	b _081DFC08
	.align 2, 0
_081DFBFC: .4byte 0x000002E6
_081DFC00:
	movs r0, #0x11
	str r0, [r5]
	bl SoftReset_0823a928
_081DFC08:
	ldr r1, _081DFC18 @ =0x030001AC
	movs r0, #0x12
_081DFC0C:
	str r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081DFC18: .4byte 0x030001AC
