	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08195A38 @ =0x00000C6C
	adds r4, r6, r0
	ldr r1, [r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	ldr r1, _08195A3C @ =0x00000CC2
	adds r5, r6, r1
	movs r1, #0
	ldrsb r1, [r5, r1]
	bl Div
	adds r0, #0x18
	ldr r2, _08195A40 @ =0x00000C34
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, [r4]
	movs r2, #0
	ldrsb r2, [r5, r2]
	adds r1, r0, #0
	adds r0, #1
	str r0, [r4]
	cmp r1, r2
	bne _08195A66
	ldr r1, _08195A44 @ =0x00000CC4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08195A4C
	movs r2, #0xc6
	lsls r2, r2, #4
	adds r1, r6, r2
	ldr r0, _08195A48 @ =FUN_08195aac
	b _08195A54
	.align 2, 0
_08195A38: .4byte 0x00000C6C
_08195A3C: .4byte 0x00000CC2
_08195A40: .4byte 0x00000C34
_08195A44: .4byte 0x00000CC4
_08195A48: .4byte FUN_08195aac
_08195A4C:
	movs r0, #0xc6
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, _08195A98 @ =FUN_08195c68
_08195A54:
	str r0, [r1]
	ldr r1, _08195A9C @ =0x00000C6C
	adds r0, r6, r1
	ldr r2, _08195AA0 @ =0x00000CC2
	adds r1, r6, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	str r1, [r0]
_08195A66:
	ldr r1, _08195AA4 @ =0x00000C36
	adds r0, r6, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	ldr r2, _08195AA8 @ =0x00000C35
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	subs r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	orrs r0, r1
	adds r2, #0x6e
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08195A98: .4byte FUN_08195c68
_08195A9C: .4byte 0x00000C6C
_08195AA0: .4byte 0x00000CC2
_08195AA4: .4byte 0x00000C36
_08195AA8: .4byte 0x00000C35
