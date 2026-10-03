	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08096A68 @ =0x00003AEB
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _08096A52
	ldr r2, _08096A6C @ =0x00003FE0
	adds r0, r6, r2
	ldrb r1, [r1]
	adds r1, r0, r1
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08096A74
_08096A52:
	ldr r1, _08096A70 @ =0x0000204C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl TextBox_Close
	bl FUN_08049e5c
	b _08096ADC
	.align 2, 0
_08096A68: .4byte 0x00003AEB
_08096A6C: .4byte 0x00003FE0
_08096A70: .4byte 0x0000204C
_08096A74:
	movs r5, #0
	ldrsb r5, [r1, r5]
	ldr r0, _08096AE4 @ =0x0000204C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08096AE8 @ =0x00002044
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0xa0
	movs r2, #0xcf
	movs r3, #1
	bl MainSprite_SetPose
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, [r6, #0x48]
	bl TextBox_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextBox_SetRect
	adds r0, r5, #0
	bl TextBox_ShowLine
	ldr r0, _08096AEC @ =0x08DAA7B0
	lsls r4, r5, #3
	adds r4, r4, r0
	ldrb r1, [r4, #1]
	movs r0, #0
	bl FUN_08049e6c
	ldrb r1, [r4, #2]
	movs r0, #1
	bl FUN_08049e6c
	ldr r0, [r6, #0x48]
	bl VM_ParseStringRef
	adds r0, #0x25
	adds r0, r0, r5
	bl Textbox_LookupString
	bl FUN_08049e30
_08096ADC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096AE4: .4byte 0x0000204C
_08096AE8: .4byte 0x00002044
_08096AEC: .4byte 0x08DAA7B0
