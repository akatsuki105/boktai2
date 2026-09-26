	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0x24
	ldrb r2, [r0]
	cmp r2, #0
	bne _0820D152
	add r0, sp, #4
	movs r1, #0x13
	strh r2, [r0]
	strh r1, [r0, #2]
	strh r2, [r0, #4]
	b _0820D160
_0820D152:
	add r1, sp, #4
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	ldr r2, _0820D17C @ =0x05000002
	bl CpuSet
_0820D160:
	ldr r1, _0820D180 @ =0x0000104C
	adds r0, r4, r1
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	str r1, [r0]
	str r2, [r0, #4]
	ldr r3, _0820D184 @ =0x000010AC
	adds r0, r4, r3
	str r1, [r0]
	str r2, [r0, #4]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820D17C: .4byte 0x05000002
_0820D180: .4byte 0x0000104C
_0820D184: .4byte 0x000010AC
