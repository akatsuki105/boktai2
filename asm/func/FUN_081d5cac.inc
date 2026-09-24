	push {r4, lr}
	mov ip, r0
	mov r4, ip
	mov r2, ip
	adds r2, #0x9c
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D5CCE
	mov r3, ip
	adds r3, #0x5e
	ldrh r0, [r3]
	movs r1, #4
	orrs r1, r0
	strh r1, [r3]
	ldrh r0, [r2]
	subs r0, #1
	b _081D5CD8
_081D5CCE:
	mov r2, ip
	adds r2, #0x5e
	ldrh r1, [r2]
	ldr r0, _081D5CF8 @ =0x0000FFFB
	ands r0, r1
_081D5CD8:
	strh r0, [r2]
	ldr r0, _081D5CFC @ =0x00000153
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D5D00
	mov r1, ip
	ldr r0, [r1, #0xc]
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _081D5D0C
	.align 2, 0
_081D5CF8: .4byte 0x0000FFFB
_081D5CFC: .4byte 0x00000153
_081D5D00:
	mov r1, ip
	ldr r0, [r1, #0xc]
	movs r1, #0xbe
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
_081D5D0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
