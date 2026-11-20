	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081F7F9C @ =0x00000123
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F7FA0
	subs r0, #1
	b _081F805C
	.align 2, 0
_081F7F9C: .4byte 0x00000123
_081F7FA0:
	movs r1, #0x85
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F805E
	mov r3, sp
	adds r4, r5, #0
	adds r4, #0x1c
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl ArcTan2_8
	ldr r2, _081F7FF4 @ =0x00000109
	adds r1, r5, r2
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _081F7FFC
	ldr r0, _081F7FF8 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081F800A
	.align 2, 0
_081F7FF4: .4byte 0x00000109
_081F7FF8: .4byte 0xFFFFFF00
_081F7FFC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081F800A
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081F800A:
	adds r0, r1, #0
	cmp r1, #0
	bge _081F8012
	rsbs r0, r1, #0
_081F8012:
	cmp r0, #0x12
	ble _081F8054
	cmp r1, #0
	ble _081F8034
	ldr r0, _081F802C @ =0x00000109
	adds r1, r5, r0
	ldr r2, _081F8030 @ =0x0000010B
	adds r0, r5, r2
	ldrb r0, [r0]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	b _081F8044
	.align 2, 0
_081F802C: .4byte 0x00000109
_081F8030: .4byte 0x0000010B
_081F8034:
	ldr r0, _081F8050 @ =0x00000109
	adds r2, r5, r0
	adds r0, #2
	adds r1, r5, r0
	ldrb r0, [r2]
	ldrb r1, [r1]
	subs r0, r0, r1
	strb r0, [r2]
_081F8044:
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r0, [r1]
	subs r0, #1
	b _081F805C
	.align 2, 0
_081F8050: .4byte 0x00000109
_081F8054:
	movs r0, #0x85
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
_081F805C:
	strb r0, [r1]
_081F805E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
