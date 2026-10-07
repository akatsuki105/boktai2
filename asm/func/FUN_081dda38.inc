	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x64
	movs r0, #0
	strh r0, [r1]
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _081DDA8C
	adds r7, r1, #0
_081DDA4E:
	ldr r0, _081DDA5C @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	bne _081DDA60
	movs r0, #0
	b _081DDA70
	.align 2, 0
_081DDA5C: .4byte 0x03002C68
_081DDA60:
	adds r0, r1, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r1, #0x58
	adds r1, r1, r0
	ldrb r0, [r1]
_081DDA70:
	adds r4, r0, #0
	bl GetSunLevel
	adds r1, r5, #0
	adds r1, #0x60
	adds r1, r1, r6
	strb r0, [r1]
	ldrh r0, [r7]
	adds r4, r4, r0
	strh r4, [r7]
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _081DDA4E
_081DDA8C:
	ldrh r1, [r5, #0x1a]
	cmp r1, #0
	bne _081DDA9A
	adds r0, r5, #0
	adds r0, #0x66
	strh r1, [r0]
	b _081DDAAC
_081DDA9A:
	adds r0, r5, #0
	adds r0, #0x64
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1a]
	bl Div
	adds r1, r5, #0
	adds r1, #0x66
	strh r0, [r1]
_081DDAAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
