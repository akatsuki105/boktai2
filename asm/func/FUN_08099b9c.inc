	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08099C08 @ =0x030046A0
	ldr r1, [r5]
	ldr r2, _08099C0C @ =0x0000400E
	adds r0, r4, r2
	ldrb r0, [r0]
	strh r0, [r1, #0x10]
	ldr r1, _08099C10 @ =0x0000400F
	adds r0, r4, r1
	ldrb r0, [r0]
	bl FUN_08099b84
	ldr r1, [r5]
	strh r0, [r1, #0x12]
	ldr r1, [r5]
	ldr r2, _08099C14 @ =0x00004010
	adds r0, r4, r2
	ldrb r0, [r0]
	strh r0, [r1, #0x14]
	ldr r0, [r5]
	adds r0, #0x10
	movs r1, #2
	bl FUN_08231d5c
	ldr r0, [r5]
	adds r0, #0x12
	movs r1, #2
	bl FUN_08231d5c
	ldr r0, [r5]
	adds r0, #0x14
	movs r1, #2
	bl FUN_08231d5c
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r4, r4, r0
	ldr r4, [r4]
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08099C00
	ldr r0, [r5]
	ldrh r1, [r0, #0x10]
	ldr r2, _08099C18 @ =0x00000456
	adds r0, r4, r2
	strb r1, [r0]
_08099C00:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099C08: .4byte 0x030046A0
_08099C0C: .4byte 0x0000400E
_08099C10: .4byte 0x0000400F
_08099C14: .4byte 0x00004010
_08099C18: .4byte 0x00000456
