	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl FUN_0823b4b8
	adds r0, r4, #0
	bl FUN_080417dc
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c50
	cmp r0, #0
	beq _08079A94
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _08079AB2
_08079A94:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _08079ACC @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_08079AB2:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c50
	cmp r0, #0
	beq _08079AD0
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08079ADC
	.align 2, 0
_08079ACC: .4byte 0x0000FFFB
_08079AD0:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08079ADC:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_08060c50
	cmp r0, #0
	beq _08079AF8
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08079B02
_08079AF8:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08079B02:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c50
	cmp r0, #0
	beq _08079B20
	ldr r1, _08079B1C @ =0x0000060C
	adds r0, r5, r1
	bl FUN_080136b4
	b _08079B28
	.align 2, 0
_08079B1C: .4byte 0x0000060C
_08079B20:
	ldr r2, _08079B5C @ =0x0000060C
	adds r0, r5, r2
	bl FUN_08013698
_08079B28:
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x2e]
	adds r0, r0, r2
	strh r0, [r5, #0x2e]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r2, _08079B60 @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08079B5C: .4byte 0x0000060C
_08079B60: .4byte 0x000003F6
