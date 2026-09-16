	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl FUN_08090148
	ldr r1, _08090C4C @ =0x0000403C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090B84
	ldr r2, _08090C50 @ =0x00002164
	adds r0, r6, r2
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0x33
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _08090C54 @ =0x0000216C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08090C58 @ =0x00002184
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08090C5C @ =0x00002186
	adds r0, r6, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strh r1, [r0]
_08090B84:
	ldr r0, _08090C60 @ =0x00002BEC
	adds r1, r6, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	mov r8, r2
	ands r0, r2
	str r0, [r1]
	ldr r0, _08090C64 @ =0x00002BE4
	adds r4, r6, r0
	adds r5, r6, #0
	adds r5, #0x80
	adds r0, r6, #0
	bl FUN_08090b10
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _08090C68 @ =0x00004052
	adds r2, r6, r1
	ldr r0, _08090C6C @ =0x00004040
	adds r7, r6, r0
	subs r1, #6
	adds r5, r6, r1
	ldrh r0, [r7]
	ldrh r1, [r5]
	subs r0, r0, r1
	ldrh r1, [r2]
	subs r1, r1, r0
	ldr r2, _08090C70 @ =0x00002C04
	adds r0, r6, r2
	movs r2, #0
	mov ip, r2
	strh r1, [r0]
	ldr r0, _08090C74 @ =0x00004054
	adds r2, r6, r0
	ldr r1, _08090C78 @ =0x00004042
	adds r4, r6, r1
	subs r0, #6
	adds r3, r6, r0
	ldrh r1, [r4]
	ldrh r0, [r3]
	subs r1, r1, r0
	ldrh r0, [r2]
	subs r0, r0, r1
	ldr r2, _08090C7C @ =0x00002C06
	adds r1, r6, r2
	strh r0, [r1]
	ldr r1, _08090C80 @ =0x00002C08
	adds r0, r6, r1
	mov r2, ip
	strh r2, [r0]
	ldr r1, _08090C84 @ =0x00004056
	adds r0, r6, r1
	ldr r2, _08090C88 @ =0x00004050
	adds r1, r6, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08090C42
	ldr r0, _08090C8C @ =0x00002C4C
	adds r1, r6, r0
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	str r0, [r1]
	ldr r0, _08090C90 @ =0x00004058
	adds r2, r6, r0
	ldrh r1, [r7]
	ldrh r0, [r5]
	subs r1, r1, r0
	ldrh r0, [r2]
	subs r0, r0, r1
	ldr r2, _08090C94 @ =0x00002C64
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, _08090C98 @ =0x0000405A
	adds r2, r6, r0
	ldrh r1, [r4]
	ldrh r0, [r3]
	subs r1, r1, r0
	ldrh r0, [r2]
	subs r0, r0, r1
	ldr r2, _08090C9C @ =0x00002C66
	adds r1, r6, r2
	strh r0, [r1]
	ldr r1, _08090CA0 @ =0x00002C68
	adds r0, r6, r1
	mov r2, ip
	strh r2, [r0]
_08090C42:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090C4C: .4byte 0x0000403C
_08090C50: .4byte 0x00002164
_08090C54: .4byte 0x0000216C
_08090C58: .4byte 0x00002184
_08090C5C: .4byte 0x00002186
_08090C60: .4byte 0x00002BEC
_08090C64: .4byte 0x00002BE4
_08090C68: .4byte 0x00004052
_08090C6C: .4byte 0x00004040
_08090C70: .4byte 0x00002C04
_08090C74: .4byte 0x00004054
_08090C78: .4byte 0x00004042
_08090C7C: .4byte 0x00002C06
_08090C80: .4byte 0x00002C08
_08090C84: .4byte 0x00004056
_08090C88: .4byte 0x00004050
_08090C8C: .4byte 0x00002C4C
_08090C90: .4byte 0x00004058
_08090C94: .4byte 0x00002C64
_08090C98: .4byte 0x0000405A
_08090C9C: .4byte 0x00002C66
_08090CA0: .4byte 0x00002C68
