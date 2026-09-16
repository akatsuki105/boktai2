	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08090148
	ldr r1, _08090D30 @ =0x0000403C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090CEC
	ldr r2, _08090D34 @ =0x00002164
	adds r0, r4, r2
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0x33
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _08090D38 @ =0x0000216C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08090D3C @ =0x00002184
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08090D40 @ =0x00002186
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_08090CEC:
	ldr r0, _08090D44 @ =0x00002BEC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08090D48 @ =0x00002BE4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x80
	movs r2, #8
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _08090D4C @ =0x00002C04
	adds r0, r4, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08090D50 @ =0x00002C4C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090D30: .4byte 0x0000403C
_08090D34: .4byte 0x00002164
_08090D38: .4byte 0x0000216C
_08090D3C: .4byte 0x00002184
_08090D40: .4byte 0x00002186
_08090D44: .4byte 0x00002BEC
_08090D48: .4byte 0x00002BE4
_08090D4C: .4byte 0x00002C04
_08090D50: .4byte 0x00002C4C
