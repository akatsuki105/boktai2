	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r2, r0, #0
	adds r7, r1, #0
	ldrb r0, [r2]
	lsls r5, r0, #0x18
	ldrb r0, [r2, #1]
	lsls r0, r0, #0x10
	orrs r5, r0
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r5, r0
	ldrb r0, [r2, #3]
	orrs r5, r0
	movs r1, #0xf0
	lsls r1, r1, #0x10
	ands r1, r5
	movs r0, #0x80
	lsls r0, r0, #0x10
	cmp r1, r0
	bne _08231FBC
	ldr r0, _08231FB8 @ =0x030046A0
	b _08231FCE
	.align 2, 0
_08231FB8: .4byte 0x030046A0
_08231FBC:
	movs r0, #0x80
	lsls r0, r0, #0xd
	cmp r1, r0
	bne _08231FCC
	ldr r0, _08231FC8 @ =0x03004690
	b _08231FCE
	.align 2, 0
_08231FC8: .4byte 0x03004690
_08231FCC:
	ldr r0, _08231FF8 @ =0x03004698
_08231FCE:
	ldr r6, [r0]
	ldr r0, _08231FFC @ =0x0000FFFF
	ands r0, r5
	adds r6, r6, r0
	lsrs r0, r5, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08232000
	adds r0, r2, #4
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	adds r4, r0, #0
	add r2, sp, #8
	mov r1, sp
	bl VM_Step
	adds r4, r0, #0
	b _08232006
	.align 2, 0
_08231FF8: .4byte 0x03004698
_08231FFC: .4byte 0x0000FFFF
_08232000:
	movs r0, #0
	str r0, [sp, #8]
	adds r4, r2, #4
_08232006:
	ldr r2, [sp, #8]
	adds r0, r6, #0
	adds r1, r5, #0
	adds r3, r7, #0
	bl FUN_08231ef0
	adds r0, r4, #0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
