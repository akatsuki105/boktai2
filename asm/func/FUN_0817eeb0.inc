	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817EFA2
	ldr r0, [r7, #0x24]
	ldr r1, [r7, #0x28]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0817EEFC
	cmp r0, #1
	bgt _0817EEE6
	cmp r0, #0
	beq _0817EEF0
	b _0817EF40
_0817EEE6:
	cmp r0, #2
	beq _0817EF08
	cmp r0, #3
	beq _0817EF28
	b _0817EF40
_0817EEF0:
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _0817EEF8 @ =0xFFFFFF00
	b _0817EF10
	.align 2, 0
_0817EEF8: .4byte 0xFFFFFF00
_0817EEFC:
	mov r0, sp
	ldrh r1, [r0, #4]
	ldr r3, _0817EF04 @ =0xFFFFFF00
	b _0817EF30
	.align 2, 0
_0817EF04: .4byte 0xFFFFFF00
_0817EF08:
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
_0817EF10:
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817EF24 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _0817EF40
	.align 2, 0
_0817EF24: .4byte 0xFFFF0000
_0817EF28:
	mov r0, sp
	ldrh r1, [r0, #4]
	movs r3, #0x80
	lsls r3, r3, #1
_0817EF30:
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0817EFAC @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_0817EF40:
	add r2, sp, #8
	mov r4, sp
	adds r3, r6, #0
	adds r3, #0x24
	ldrh r0, [r6, #0x24]
	mov r1, sp
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r1, r7, #0
	adds r1, #0x42
	strb r0, [r1]
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817EFA2
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0817EFA2
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _0817EFB0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0817EFA2:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817EFAC: .4byte 0xFFFF0000
_0817EFB0: .4byte 0xFEFFFFFF
