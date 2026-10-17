	push {lr}
	mov ip, r0
	ldr r0, _081DB368 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _081DB36C @ =0x00005260
	adds r2, r0, r1
	movs r1, #0xb9
	lsls r1, r1, #2
	add r1, ip
	movs r3, #0xf
_081DB340:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _081DB340
	movs r0, #0xb9
	lsls r0, r0, #2
	add r0, ip
	mov r1, ip
	str r0, [r1, #0x68]
	movs r1, #0xc1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081DB368: .4byte 0x03003584
_081DB36C: .4byte 0x00005260
