	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	movs r5, #0
	ldr r0, _08177FC8 @ =0x00001012
	adds r7, r3, r0
	movs r2, #0
	ldrsh r0, [r7, r2]
	cmp r5, r0
	bge _08177FBE
	ldr r2, [r1, #4]
	ldr r1, [r1]
	ldr r6, _08177FCC @ =0x00000764
	adds r4, r3, r6
	ldr r0, _08177FD0 @ =0x00000674
	adds r3, r3, r0
	movs r6, #0x92
	lsls r6, r6, #1
	mov r8, r6
	mov ip, r7
_08177FA6:
	str r1, [r3]
	str r2, [r3, #4]
	str r1, [r4]
	str r2, [r4, #4]
	add r4, r8
	add r3, r8
	adds r5, #1
	mov r7, ip
	movs r6, #0
	ldrsh r0, [r7, r6]
	cmp r5, r0
	blt _08177FA6
_08177FBE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08177FC8: .4byte 0x00001012
_08177FCC: .4byte 0x00000764
_08177FD0: .4byte 0x00000674
