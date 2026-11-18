	push {r4, r5, lr}
	mov ip, r0
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0]
	mov r2, ip
	ldrb r0, [r2, #6]
	adds r0, #0x14
	strb r0, [r2, #6]
	adds r2, #0xf8
	ldrh r0, [r2]
	mov r3, ip
	ldrh r3, [r3, #0x1c]
	adds r0, r0, r3
	mov r4, ip
	strh r0, [r4, #0x1c]
	mov r3, ip
	adds r3, #0xfc
	ldrh r0, [r3]
	ldrh r5, [r4, #0x20]
	adds r0, r0, r5
	strh r0, [r4, #0x20]
	ldr r0, _08198DF8 @ =0x00000CEC
	adds r1, r1, r0
	ldr r0, [r1]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08198D4A
	b _08198E46
_08198D4A:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne _08198E0E
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	bne _08198E0E
	mov r1, ip
	adds r1, #0xa2
	movs r0, #0x10
	strh r0, [r1]
	subs r1, #0x50
	strh r0, [r1]
	ldrh r0, [r4, #0x1c]
	movs r2, #0x96
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	ldrh r0, [r4, #0x1e]
	movs r4, #0x97
	lsls r4, r4, #1
	add r4, ip
	strh r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0x20]
	movs r3, #0x98
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	movs r1, #0x9a
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r2, #0x9e
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	movs r1, #0x9b
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r4]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0x9f
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	movs r1, #0x9c
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r3, #0xa0
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	movs r1, #0xc1
	lsls r1, r1, #1
	add r1, ip
	ldrb r0, [r1]
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r1, _08198DFC @ =0x00000185
	add r1, ip
	movs r0, #0xf6
	strb r0, [r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	cmp r1, #0
	bge _08198DE0
	rsbs r1, r1, #0
_08198DE0:
	movs r5, #0
	ldrsh r0, [r3, r5]
	cmp r0, #0
	bge _08198DEA
	rsbs r0, r0, #0
_08198DEA:
	cmp r1, r0
	bge _08198E04
	movs r1, #0xb6
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _08198E00 @ =FUN_08198b44
	b _08198E0C
	.align 2, 0
_08198DF8: .4byte 0x00000CEC
_08198DFC: .4byte 0x00000185
_08198E00: .4byte FUN_08198b44
_08198E04:
	movs r1, #0xb6
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _08198E20 @ =FUN_08198c28
_08198E0C:
	str r0, [r1]
_08198E0E:
	mov r0, ip
	adds r0, #0xf8
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r2, r0, #0
	cmp r1, #0
	blt _08198E24
	asrs r0, r1, #1
	b _08198E2A
	.align 2, 0
_08198E20: .4byte FUN_08198c28
_08198E24:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08198E2A:
	strh r0, [r2]
	mov r0, ip
	adds r0, #0xfc
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r2, r0, #0
	cmp r1, #0
	blt _08198E3E
	asrs r0, r1, #1
	b _08198E44
_08198E3E:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08198E44:
	strh r0, [r2]
_08198E46:
	pop {r4, r5}
	pop {r0}
	bx r0
