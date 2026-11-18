	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r1, _08199F90 @ =0x00000C9C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _08199F86
	ldr r0, _08199F94 @ =0x085ADDB0
	mov r8, r0
	ldr r1, _08199F98 @ =0x0000056A
	adds r5, r6, r1
	ldr r0, _08199F9C @ =0x00000454
	adds r4, r6, r0
_08199F64:
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r5, r5, r1
	adds r4, r4, r1
	adds r7, #1
	ldr r1, _08199F90 @ =0x00000C9C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08199F64
_08199F86:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08199F90: .4byte 0x00000C9C
_08199F94: .4byte 0x085ADDB0
_08199F98: .4byte 0x0000056A
_08199F9C: .4byte 0x00000454
