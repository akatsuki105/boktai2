	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	adds r3, r5, #0
	adds r3, #0x9c
	ldr r0, _0810BAFC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810BB00
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810BB02
	.align 2, 0
_0810BAFC: .4byte 0x0000046D
_0810BB00:
	movs r0, #0
_0810BB02:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _0810BB10
	b _0810BFB6
_0810BB10:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r4, _0810BB60 @ =0x0000046A
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #6
	beq _0810BB64
	cmp r0, #0x14
	beq _0810BB64
	movs r1, #0x89
	lsls r1, r1, #7
	mov r6, sb
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _0810BB64
	ldr r0, [r3, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _0810BB6C
	.align 2, 0
_0810BB60: .4byte 0x0000046A
_0810BB64:
	movs r4, #0xee
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r1, [r0]
_0810BB6C:
	asrs r0, r1, #1
	cmp r2, r0
	bne _0810BBE8
	ldr r6, _0810BBD8 @ =0x0000046B
	adds r0, r5, r6
	movs r4, #0
	movs r3, #1
	strb r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0810BB8C
	b _0810C198
_0810BB8C:
	movs r1, #3
	subs r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0810BBDC @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	ldr r2, _0810BBE0 @ =0x0000046A
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r3, [r0]
	ldr r2, _0810BBE4 @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r6, #0x17
	adds r0, r5, r6
	strb r3, [r0]
	ldr r3, _0810BBD8 @ =0x0000046B
	adds r0, r5, r3
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _0810C198
	.align 2, 0
_0810BBD8: .4byte 0x0000046B
_0810BBDC: .4byte 0x00000469
_0810BBE0: .4byte 0x0000046A
_0810BBE4: .4byte 0x000005BC
_0810BBE8:
	cmp r2, #1
	bne _0810BBEE
	b _0810BCEC
_0810BBEE:
	cmp r2, #1
	bgt _0810BBF8
	cmp r2, #0
	beq _0810BC06
	b _0810BFB6
_0810BBF8:
	cmp r2, #2
	bne _0810BBFE
	b _0810BDB8
_0810BBFE:
	cmp r2, #3
	bne _0810BC04
	b _0810BE84
_0810BC04:
	b _0810BFB6
_0810BC06:
	subs r0, r1, #2
	cmp r0, #3
	bhi _0810BC80
	movs r3, #0x99
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrb r2, [r0]
	ldr r4, _0810BC34 @ =0x0000025D
	adds r0, r5, r4
	ldrb r3, [r0]
	cmp r3, #0
	bne _0810BC3C
	ldr r6, _0810BC38 @ =0x000004B7
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _0810BEAC
	.align 2, 0
_0810BC34: .4byte 0x0000025D
_0810BC38: .4byte 0x000004B7
_0810BC3C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, #1
	ldr r1, _0810BC78 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810BC7C @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0810BC66
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810BC66
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810BC66
	b _0810BF0A
_0810BC66:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0810BEF4
	.align 2, 0
_0810BC78: .4byte 0x000004B7
_0810BC7C: .4byte 0x0000046E
_0810BC80:
	movs r4, #0x99
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r6, _0810BCAC @ =0x0000025D
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810BCB4
	ldr r1, _0810BCB0 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #4
	str r3, [sp]
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0810BCD8
	.align 2, 0
_0810BCAC: .4byte 0x0000025D
_0810BCB0: .4byte 0x000004B7
_0810BCB4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r3, _0810BCE4 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	movs r3, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
_0810BCC6:
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0810BCD8:
	ldr r4, _0810BCE8 @ =0x0000046E
	adds r1, r5, r4
	movs r0, #0
	strb r0, [r1]
	b _0810BFA8
	.align 2, 0
_0810BCE4: .4byte 0x000004B7
_0810BCE8: .4byte 0x0000046E
_0810BCEC:
	subs r0, r1, #4
	cmp r0, #3
	bhi _0810BD64
	movs r1, #0x99
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, _0810BD18 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0810BD20
	ldr r4, _0810BD1C @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _0810BEAC
	.align 2, 0
_0810BD18: .4byte 0x0000025D
_0810BD1C: .4byte 0x000004B7
_0810BD20:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, #2
	ldr r1, _0810BD5C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810BD60 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0810BD4A
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810BD4A
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810BD4A
	b _0810BF0A
_0810BD4A:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0810BEF4
	.align 2, 0
_0810BD5C: .4byte 0x000004B7
_0810BD60: .4byte 0x0000046E
_0810BD64:
	movs r4, #0x99
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r6, _0810BD90 @ =0x0000025D
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810BD98
	ldr r1, _0810BD94 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #4
	str r3, [sp]
	movs r3, #1
	bl AuxAnim_SetAnim
	b _0810BCD8
	.align 2, 0
_0810BD90: .4byte 0x0000025D
_0810BD94: .4byte 0x000004B7
_0810BD98:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	adds r2, #1
	ldr r3, _0810BDB4 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	movs r3, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0810BCC6
	.align 2, 0
_0810BDB4: .4byte 0x000004B7
_0810BDB8:
	subs r0, r1, #1
	cmp r0, #4
	bls _0810BE30
	movs r1, #0x99
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, _0810BDEC @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810BDF4
	ldr r4, _0810BDF0 @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #5
	str r3, [sp]
	movs r3, #1
	bl AuxAnim_SetAnim
	b _0810BE1C
	.align 2, 0
_0810BDEC: .4byte 0x0000025D
_0810BDF0: .4byte 0x000004B7
_0810BDF4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	adds r2, #1
	ldr r6, _0810BE28 @ =0x000004B7
	adds r0, r5, r6
	strb r2, [r0]
	movs r3, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #8]
_0810BE1C:
	ldr r0, _0810BE2C @ =0x0000046E
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _0810BF0A
	.align 2, 0
_0810BE28: .4byte 0x000004B7
_0810BE2C: .4byte 0x0000046E
_0810BE30:
	movs r4, #0x99
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r6, _0810BE5C @ =0x0000025D
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810BE64
	ldr r1, _0810BE60 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #4
	str r3, [sp]
	movs r3, #2
	bl AuxAnim_SetAnim
	b _0810BCD8
	.align 2, 0
_0810BE5C: .4byte 0x0000025D
_0810BE60: .4byte 0x000004B7
_0810BE64:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	adds r2, #2
	ldr r3, _0810BE80 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	movs r3, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0810BCC6
	.align 2, 0
_0810BE80: .4byte 0x000004B7
_0810BE84:
	cmp r1, #3
	bhi _0810BF24
	movs r1, #0x99
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, _0810BEB8 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0810BEC4
	ldr r4, _0810BEBC @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_0810BEAC:
	bl AuxAnim_SetAnim
	ldr r0, _0810BEC0 @ =0x0000046E
	adds r6, r5, r0
	b _0810BF06
	.align 2, 0
_0810BEB8: .4byte 0x0000025D
_0810BEBC: .4byte 0x000004B7
_0810BEC0: .4byte 0x0000046E
_0810BEC4:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r1, _0810BF1C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810BF20 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0810BEEA
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810BEEA
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0810BF0A
_0810BEEA:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
_0810BEF4:
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0810BF06:
	movs r0, #0
	strb r0, [r6]
_0810BF0A:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0810BFB6
	.align 2, 0
_0810BF1C: .4byte 0x000004B7
_0810BF20: .4byte 0x0000046E
_0810BF24:
	movs r4, #0x99
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r6, _0810BF54 @ =0x0000025D
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810BF60
	ldr r1, _0810BF58 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #1
	str r3, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _0810BF5C @ =0x0000046E
	adds r6, r5, r2
	b _0810BFA4
	.align 2, 0
_0810BF54: .4byte 0x0000025D
_0810BF58: .4byte 0x000004B7
_0810BF5C: .4byte 0x0000046E
_0810BF60:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, #1
	ldr r3, _0810BFF8 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r4, _0810BFFC @ =0x0000046E
	adds r6, r5, r4
	cmp r1, r2
	bne _0810BF88
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810BF88
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810BFA8
_0810BF88:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r4, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
_0810BFA4:
	movs r0, #0
	strb r0, [r6]
_0810BFA8:
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r1, _0810C000 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0810BFB6:
	ldr r0, [r5, #0x44]
	adds r1, r0, #0
	adds r1, #0x20
	ldrh r0, [r1, #0xc]
	cmp r0, #0
	bne _0810C028
	ldrh r0, [r1, #0x14]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0810C028
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r1, r0, #5
	adds r0, r1, #0
	mov r3, r8
	ldrb r2, [r3, #5]
	subs r0, r2, r0
	cmp r0, #0
	bge _0810BFEC
	rsbs r0, r0, #0
_0810BFEC:
	cmp r0, #0x20
	bgt _0810C004
	mov r4, r8
	strb r1, [r4, #5]
	b _0810C028
	.align 2, 0
_0810BFF8: .4byte 0x000004B7
_0810BFFC: .4byte 0x0000046E
_0810C000: .4byte 0xFFFEFFFF
_0810C004:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810C020
	adds r0, r2, #0
	adds r0, #0x20
	mov r1, r8
	strb r0, [r1, #5]
	b _0810C028
_0810C020:
	adds r0, r2, #0
	subs r0, #0x20
	mov r2, r8
	strb r0, [r2, #5]
_0810C028:
	ldr r1, _0810C040 @ =0x0000A02F
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0810C048
	ldr r4, _0810C044 @ =0x00000482
	adds r1, r5, r4
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0810C058
	.align 2, 0
_0810C040: .4byte 0x0000A02F
_0810C044: .4byte 0x00000482
_0810C048:
	ldr r6, _0810C07C @ =0x00000482
	adds r0, r5, r6
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0810C058
	movs r0, #1
	strh r0, [r2]
_0810C058:
	ldr r1, _0810C080 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810C084
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _0810C09C
	.align 2, 0
_0810C07C: .4byte 0x00000482
_0810C080: .4byte 0x0000025D
_0810C084:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_0810C09C:
	ldr r2, _0810C150 @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810C198
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r2, #8
	rsbs r2, r2, #0
	ldr r3, _0810C154 @ =0x0000046B
	adds r4, r5, r3
	movs r7, #0
	movs r6, #1
	strb r6, [r4]
	adds r1, #0xdd
	adds r3, r5, r1
	ldrb r1, [r3]
	orrs r0, r2
	subs r1, r1, r0
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _0810C0D6
	movs r0, #8
	subs r1, r0, r1
_0810C0D6:
	adds r0, r1, #0
	cmp r0, #0
	bge _0810C0DE
	rsbs r0, r0, #0
_0810C0DE:
	cmp r0, #0
	bne _0810C16C
	strb r6, [r4]
	ldrb r0, [r3]
	adds r0, #5
	lsls r0, r0, #5
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0810C198
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _0810C158 @ =0x00000469
	adds r0, r5, r4
	strb r6, [r0]
	ldr r1, _0810C15C @ =0x0000046A
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _0810C160 @ =0x00000484
	adds r0, r5, r2
	str r7, [r0]
	adds r3, #4
	adds r0, r5, r3
	strb r6, [r0]
	ldr r4, _0810C164 @ =0x000005BC
	adds r0, r5, r4
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	adds r0, r5, r3
	strb r6, [r0]
	ldr r4, _0810C154 @ =0x0000046B
	adds r0, r5, r4
	strb r7, [r0]
	ldr r6, _0810C168 @ =0x00000553
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	b _0810C196
	.align 2, 0
_0810C150: .4byte 0x0000046E
_0810C154: .4byte 0x0000046B
_0810C158: .4byte 0x00000469
_0810C15C: .4byte 0x0000046A
_0810C160: .4byte 0x00000484
_0810C164: .4byte 0x000005BC
_0810C168: .4byte 0x00000553
_0810C16C:
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r2, [r0]
	movs r1, #2
	ldr r4, _0810C1A8 @ =0x0000046D
	adds r0, r5, r4
	strb r6, [r0]
	ldr r6, _0810C1AC @ =0x0000046B
	adds r0, r5, r6
	strb r7, [r0]
	subs r3, #0x3d
	adds r0, r5, r3
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
_0810C196:
	strh r7, [r0]
_0810C198:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810C1A8: .4byte 0x0000046D
_0810C1AC: .4byte 0x0000046B
